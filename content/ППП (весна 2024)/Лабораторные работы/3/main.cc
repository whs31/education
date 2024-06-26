/*
 * Лабораторная работа 3
 * Студент: Рязанцев Дмитрий
 */

#include <cmath>
#include <concepts>
#include <iostream>
#include <format>
#include <regex>
#include <vector>
#include <fstream>
#include <filesystem>

using std::string;
using std::string_view;
using std::vector;
namespace fs = std::filesystem;

namespace
{
  [[nodiscard]] auto first_words_of_sentences(string const& text) -> vector<string>
  {
    using std::sregex_token_iterator;
    using std::sregex_iterator;
    using std::smatch;
    using std::regex;

    auto const pattern = regex(R"([\.\!\?][\s]*([A-Z][\w]+)*)");
    auto result = vector<string>();
    result.push_back(text.substr(0, text.find_first_of(" \t\n") + 1));
    for(auto it = sregex_iterator(text.begin(), text.end(), pattern); it != sregex_iterator(); ++it)
      result.push_back(it->str(1));
    return result;
  }

  [[nodiscard]] auto count_word(string const& text, string_view const word) -> size_t  // NOLINT(*-no-recursion)
  {
    auto const pos = text.find(word.data());
    if(pos == string::npos)
      return 0;
    return 1 + count_word(text.substr(pos + word.size()), word);
  }
}

auto main() -> int
{
  using std::cin;
  using std::cout;
  using std::cerr;
  using std::endl;

  auto const path = []() -> fs::path {
    cout << "Enter path to text file: " << endl;
    auto p = fs::path();
    cin >> p;
    auto joined = fs::current_path() / p;
    if(not exists(joined)) {
      cerr << std::format("File {} doesn't exist", joined.string()) << endl;
      std::exit(1);
    }
    return joined;
  }();

  if(path.extension() != ".txt") {
    cerr << "File must have .txt extension" << endl;
    std::exit(1);
  }

  auto const text = [](fs::path const& filepath) -> string {
    using std::ifstream;
    using std::istreambuf_iterator;

    auto handle = ifstream(filepath);
    if(handle.fail()) {
      cerr << std::format("Can't open file {}", filepath.string()) << endl;
      std::exit(1);
    }
    return {istreambuf_iterator<char>(handle), istreambuf_iterator<char>()};
  }(path);

  auto is_all_whitespace = [](string const& word) -> bool { return word.find_first_not_of(" \t\n") == string::npos; };
  if(text.empty() or is_all_whitespace(text)) {
    cerr << "File is empty" << endl;
    std::exit(1);
  }

  auto join = [=](vector<string> const& words) -> string {
    auto result = string();
    for(auto const& word : words)
      result += word.empty() or is_all_whitespace(word) ? "" : word + " ";
    return result;
  };

  const auto [first, second] = [](string const& txt) -> std::pair<string, string> {
    auto const pos = txt.find_first_of(" \t\n");
    auto const second_pos = txt.find_first_of(" \t\n", pos + 1);
    if(pos == string::npos)
      return {"", ""};
    return {txt.substr(0, pos), txt.substr(pos + 1, second_pos - pos - 1)};
  }(text.substr(text.find_first_not_of(" \t\n"), text.size() - text.find_first_not_of(" \t\n")));

  if(first.empty() or second.empty()) {
    cerr << "File doesn't contain two words" << endl;
    std::exit(1);
  }

  cout << endl;
  cout << std::format("First two words: [{}, {}]\n", first, second);
  cout << std::format("Count of word \"{}\": {}\n", first, count_word(text, first));
  cout << std::format("Count of word \"{}\": {}\n", second, count_word(text, second));
  cout << std::format("First words of sentences: [\n{}\n]\n", join(first_words_of_sentences(text)));
  return 0;
}