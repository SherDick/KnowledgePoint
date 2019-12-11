##<font color=#FF4500>基类的析构函数不为虚函数</font>
```
class Base {
public:
	Base(int a = 0) {
		cout << "Base default constructor" << endl;
		p = new int(a);
	}
	~Base() {
		cout << "Base destructor" << endl;
		if (nullptr != p) {
			delete p;
			p = nullptr;
		}
	}
private:
	int *p;
};
class Inherit : public Base {
public:
	Inherit(int b = 0) {
		cout << "Inherit default constructor" << endl;
		q = new int(b);
	}
	~Inherit() {
		cout << "Inherit destructor" << endl;
		if (nullptr != q) {
			delete q;
			q = nullptr;
		}
	}
private:
	int *q;
};
```
##<font color=#FF4500>基类对派生类及对象不需要进行操作时。</font>
```
int main(void)
{
	Base *b = new Base(2);
	delete b;
	b = nullptr;
	return 0;
}
```
![](https://i.imgur.com/ApaTG7N.png)
　　这时不能定义虚函数，因为这样会增加内存开销。当类里面有定义虚函数时，编译器会给类增加一个虚函数表，里面来存放虚函数指针，这样就增加了类的存储空间。只有当一个类被用来作为基类的时候，才把析构函数写成虚函数。
##<font color=#FF4500>基类的析构函数为虚函数</font>
```
class Base {
public:
	Base(int a = 0) {
		cout << "Base default constructor" << endl;
		p = new int(a);
	}
	virtual ~Base() {
		cout << "Base destructor" << endl;
		if (nullptr != p) {
			delete p;
			p = nullptr;
		}
	}
private:
	int *p;
};
class Inherit : public Base {
public:
	Inherit(int b = 0) {
		cout << "Inherit default constructor" << endl;
		q = new int(b);
	}
	~Inherit() {
		cout << "Inherit destructor" << endl;
		if (nullptr != q) {
			delete q;
			q = nullptr;
		}
	}
private:
	int *q;
};
```
##<font color=#FF4500>示例</font>
```
int main(void)
{
	Base *b = new Inherit(3);
	delete b;
	b = nullptr;
	return 0;
}
```
![](https://i.imgur.com/7MlAiGl.png)