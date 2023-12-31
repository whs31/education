# Задачи

# Ответы
###### **1.** Найти все значения корня $\sqrt[6]{\frac{-1-i\sqrt{3}}{2}}$ и изобразить их на комплексной плоскости.
- $Re(z) = -\frac{1}{2}, \ Im(z) = -\frac{\sqrt{3}}{2}$
- $|z|=r=\sqrt{(-\frac{1}{2})^2+(-\frac{\sqrt{3}}{2})^2}=1$ 
- $arg \ z = \varphi = arctg(\frac{\frac{\sqrt{3}}{2}}{\frac{1}{2}})=\frac{\pi}{3}$ 
- По *формуле Муавра*: 
	- $\sqrt[6]{z} = \sqrt[6]{r}(cos(\frac{\varphi+2\pi k}{n})+isin(\frac{\varphi+2\pi k}{n})), \ k=0,1,2,...,n-1$
	- $\sqrt[6]{\frac{-1-i\sqrt{3}}{2}}=cos(\frac{\frac{\pi}{3}+2\pi k}{6})+isin(\frac{\frac{\pi}{3}+2\pi k}{6})$ 
	- Для каждого $k = 0,1,2,3,4,5$:
		- $k=0, \ x=cos(\frac{\pi}{18}), \ y=sin(\frac{\pi}{18})$
		- $k=1, \ x=cos(\frac{7\pi}{18}), \ y=sin(\frac{7\pi}{18})$
		- $k=2, \ x=cos(\frac{13\pi}{18}), \ y=sin(\frac{13\pi}{18})$
		- $k=3, \ x=cos(\frac{19\pi}{18}), \ y=sin(\frac{19\pi}{18})$
		- $k=4, \ x=cos(\frac{25\pi}{18}), \ y=sin(\frac{25\pi}{18})$
		- $k=5, \ x=cos(\frac{31\pi}{18}), \ y=sin(\frac{31\pi}{18})$

###### **2.** Вычислить $(\frac{1+i\sqrt{3}}{2+2i})^{32}$. Ответ записать в алгебраической форме.
- $z_{1}=1+i\sqrt{3}, \ \ z_2=2+2i$
- $|z|=\frac{|z_1|}{|z_{2|}}, \ \ \varphi=\varphi_1-\varphi_2$
- $|z_1|=\sqrt{1+3}=2, \ \ |z_{2}|=\sqrt{4+4}=2\sqrt{2}$ 
- $\varphi_1=arctg(\frac{\sqrt{3}}{1})=\frac{\pi}{3}, \ \ \varphi_2=arctg(\frac{2}{2})=\frac{\pi}{4}$ 
- $|z|=\frac{2}{2\sqrt{2}}=\frac{\sqrt{2}}{2}$
- $\varphi=\frac{\pi}{3}-\frac{\pi}{4}=\frac{\pi}{12}$ 
- По *формуле Муавра*: 
	- $z^{32}=(\frac{\sqrt{2}}{2})^{32}(cos(32*\frac{\pi}{12})+isin(32*\frac{\pi}{12}))=\frac{1}{65536}(cos(\frac{8\pi}{3})+isin(\frac{8\pi}{3}))$ 
	- $z^{32}=\frac{-\frac{1}{2}+i\frac{\sqrt{3}}{2}}{65536}=-\frac{1}{131072}+i\frac{\sqrt{3}}{131072}$ 

###### **3.** Представить в алгебраической форме числа $cos(\frac{\pi}{6}-i); \ \ sin(\frac{\pi}{3}+i)$.
- *Формулы приведения:*
$$\begin{array}{cl}&sin(a+b)=sin(a)cos(b)+cos(a)sin(b) \\& cos(a+b)=cos(a)cos(b)-sin(a)sin(b)\end{array}$$
- $cos(\frac{\pi}{6}-i)=cos\frac{\pi}{6}cos(-i)+sin\frac{\pi}{6}sin(-i)=\frac{1}{2}(\sqrt{3}cos(-i)+sin(-i))$
- По *формулам гиперболических функций:*
$$\begin{array}{cl}&cos(iz) = ch(z), \ \ sin(iz)=i*sh(z) \\&sh(x) = \frac{e^{x}-e^{-x}}{2}, \ \ ch(x)=\frac{e^x+e^{-x}}{2} \end{array}$$
- $cos(\frac{\pi}{6}-i)=\frac{\sqrt{3}ch(-1)+i*sh(-1)}{2}$
- $ch(-1)=\frac{e^{-1}+e}{2}, \ \ sh(-1)=\frac{e^{-1}-e}{2}$
- $z = \frac{\sqrt{3}}{4}(\frac{1}{e}+e)+i*\frac{1}{4}(\frac{1}{e}-e)$
