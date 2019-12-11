##<font color=#FF8C00>默认构造函数</font>
　　默认的构造函数存在一定的弊端，属于浅拷贝。比如指针的简单的指向一个变量。
```
class Base {
public:
	Base(int a = 0){
		cout << "default constructor" << endl;
		p = new int(a);
    }
	~Base(){
		cout << "destructor" << endl;
		cout << p << endl;
		if (p != nullptr){
			delete p;
			p = nullptr;
		}
	}
private:
	int *p;
};

int main(void)
{
	Base b1(1);
	return 0;
}
```
![](https://i.imgur.com/1wa3s5i.png)
　　当没有定义拷贝构造函数时，会默认生成一个默认拷贝构造函数。
##<font color=#FF1493>默认的构造函数</font>
```
Base::Base(const Base& base) {
	p = base.p;/*仅是简单的指针指向指向被拷贝者*/
}
```
```
int main(void)
{
	Base b1(1);
	Base b2(b1);
	return 0;
}
```
![](https://i.imgur.com/WIPhUAD.png)
　　会发现，两个类对象中的变量指向的内存地址都是一样的。这样当调用析构函数时，对该地址释放两次，造成错误。
　　也可以看出，默认拷贝构造函数属于浅拷贝，只是简单将拷贝者和被拷贝者指向同一地址。


##<font color=#FF1493>自定义拷贝构造函数</font>
```
Base::Base(const Base& base) {
	p = new int(*base.p);
}
```
![](https://i.imgur.com/pAwtrOL.png)
　　这样会发现两个地址不一样了。不会造成对同一地址重复释放，导致程序崩溃。
