Словарь - это **ассоциативный массив**. Это значит, что в словаре данные хранятся попарно: ключ и значение.
Пример: 
- Телефонная книга - это словарь: ключ - имя человека (`str`), значение - его телефон (`str`)
- Меню в ресторане - это словарь: ключ - название блюда (`str`), значение - его цена (`int`)

Обычно в словаре ключем выступает строка (`str`) или же число (`int`). Значением может быть что угодно - например, список `list` или же другой словарь `dict`.

Словари в языке Python объявляются с использованием ключевого слова `dict` или фигурных скобок `{}`.

Для получения данных из словаря или записи в них используются те же квадратные скобки, что и в списках (`[]`). Однако, вместо индекса элемента, в словаре в них передается *ключ*, например, строка.

Пример - объявим словарь с простой структурой:
- Ключ $key$ - имя студента
- Значение $value$ - его возраст
```python
students = dict()

# добавить в словарь значение 
students['Alexa'] = 18
students['Nikita'] = 20
students['Kolya'] = 23
students['Oleg'] = 19

# выведем отдельное значение:
print(students['Alexa'])

# выведем весь словарь
print(students)
```
Вывод:
```bash
18
{'Alexa': 18, 'Nikita': 20, 'Kolya': 23, 'Oleg': 19}
```

#### Методы у словаря
###### Очистить словарь:
Для этого используем метод `clear()`:
```python
drinks = {
	'coffee': 'tasty',
	'tea': 'tasty',
	'water': 'tasty',
	'cola': 'tasty',
	'sprite': 'not tasty =('
}

drinks.clear()
print(drinks) # выведет пустой словарь - {} 
```

###### Получить все ключи и получить пары ключ-значение:
Зачастую по словарю нужно итерироваться через цикл. Для этого мы можем получить все ключи в словаре - метод `keys()`, и все пары ключ-значение - метод `items()`. Оба этих метода вернут списки:
```python
drinks = {
	'coffee': 'tasty',
	'tea': 'tasty',
	'water': 'tasty',
	'cola': 'tasty',
	'sprite': 'not tasty =('
}

print(drinks.keys())    # выведет все ключи
print(drinks.items())   # выведет все ключи в паре со значениями

# выведем пару ключ-значение, если имя напитка начинается на c:
for drink in drinks.keys():
	if drink.startswith('c'):
		print(drink, end=" ") 

print()

# выведем имя напитка, если его значение - не tasty:
for drink, tastiness in drinks.items(): 
	if tastiness != 'tasty':
		print(f'Drink {drink} is not tasty!')
```
Вывод:
```bash
dict_keys(['coffee', 'tea', 'water', 'cola', 'sprite']) 
dict_items([('coffee', 'tasty'), ('tea', 'tasty'), ('water', 'tasty'), ('cola', 'tasty'), ('sprite', 'not tasty =(')]) 
coffee cola  
Drink sprite is not tasty!
```

###### Удалить один элемент из словаря:
Для этого используем метод `pop(...)`
```python
prices = {
	'eggs': 10.0,
	'milk': 5.0,
	'butter': 7.0,
	'water': 2.0,
	'tea': 4.0
}

# запишем все элементы дешевле 6.0 в новый словарь
cheap = dict()
for key, price in prices.items():
	if price <= 6:
		cheap[key] = price

# удалим из старого словаря все, что дешевле 6.0
for key in cheap.keys():
	prices.pop(key)

print(prices)
```
Вывод:
```bash
{'eggs': 10.0, 'butter': 7.0}
```

##### Примеры задач на словари:
###### Найти, сколько раз разные буквы встречаются в тексте:
```python
text = 'いろはにほへと ちりぬるを わかよたれそ つねならむ うゐのおくやま けふこえて あさきゆめみし ゑひもせす'

kanjis = dict()
for letter in text:
	if not letter.isalpha():
		continue
	if letter in kanjis:
		kanjis[letter] += 1
	else: 
		kanjis[letter] = 1

print(kanjis)
```
Программа выведет словарь, в котором каждой букве будет соответствовать номер 1 (потому что буквы в тексте не повторяются).

###### Преобразовать строку в словарь:
Дана строка из названий блюд и эмодзи. Нужно поместить все это в словарь с ключем - названием блюда и значением - эмодзи:
```python
food = 'sushi 😊, pizza 😊, soup 😊, omelette 😡, spaghetti 😡, fries 😊'

food = food.split(", ")
food_dict = dict()
for dish in food:
	name = dish.split()[0]
	emoji = dish.split()[1]
	food_dict[name] = emoji
print(food_dict)

# красивый вывод словаря в столбик:
for dish, emoji in food_dict.items():
	print(f'Dish: {dish} - {emoji}')
```
Вывод:
```bash
{'sushi': '😊', 'pizza': '😊', 'soup': '😊', 'omelette': '😡', 'spaghetti': '😡', 'fries': '😊'} 

Dish: sushi - 😊 
Dish: pizza - 😊 
Dish: soup - 😊 
Dish: omelette - 😡 
Dish: spaghetti - 😡 
Dish: fries - 😊
```