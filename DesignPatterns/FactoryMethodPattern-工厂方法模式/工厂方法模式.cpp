/*
 *FileName:工厂方法模式
 *Date:2018.7.23
 *Description:
 */
#include <iostream>
#include <cstdlib>
using namespace std;
/*创建一个水果抽象类供具体的水果实现和抽象工厂的返回*/
class AbstractFruit {
public:
	virtual void showFruitName() = 0;
};
/*若想添加一种新水果，则不再需要去修改其中任何一个类，
   而只需要实现一个新水果工厂和一个新水果具体类即可*/
class Apple :public AbstractFruit {
public:
	virtual void showFruitName() {
		cout << "Apple" << endl;
	}
};

class Orange : public AbstractFruit {
public:
	virtual void showFruitName() {
		cout << "orange" << endl;
	}
};
/*创建一个抽象工厂类，供具体的水果工厂实现，并返回抽象水果类*/
class AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};
/*实现抽象工厂，并返回一个抽象水果指针*/
class AppleFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() {
		return new Apple;
	}
};

class OrangeFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() {
		return new Orange;
	}
};

void test() {
	/*根据依赖倒转原则，是针对接口的编程。即只需要使用抽象工厂
	  类的指针和抽象水果类的指针，通过多态的特性，就可以完成具
	  体类的业务。*/
	AbstractFruitFactory *FruitFactory = NULL;
	AbstractFruit *fruit = NULL;
	/*抽象类指针，完成Apple业务*/
	FruitFactory = new AppleFactory;
	fruit = FruitFactory->CreateFruit();
	fruit->showFruitName();
	delete fruit;
	delete FruitFactory;
}

int main(int argc, char **argv) 
{
	test();
	return 0;
}