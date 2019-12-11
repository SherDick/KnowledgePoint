/*
 *FileName:简单工厂模式
 *Date:2018.7.23
 *Description:
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//抽象产品
class AbstractFruit {
public:
	virtual void showFruitName() = 0;
};

//具体产品
class Apple :public AbstractFruit {
public:
	virtual void showFruitName() {
		cout << "Apple" << endl;
	}
};
//具体产品
class Orange : public AbstractFruit {
public:
	virtual void showFruitName() {
		cout << "orange" << endl;
	}

};
//工厂
class FruitFactory{
public:
	static AbstractFruit * CreateFruit(string flag) {
		if (flag == "Apple") {
			return new Apple;
		}
		else if (flag == "Orange") {
			return new Orange;
		}
		else {
			return NULL;
		}
	}
};

void test() {
	FruitFactory *factory = new FruitFactory;
	AbstractFruit *fruit = factory->CreateFruit("Apple");
	fruit->showFruitName();
	delete fruit;
	fruit = NULL;
	
	fruit = factory->CreateFruit("Orange");
	fruit->showFruitName();
	delete fruit;
	fruit = NULL;
	delete factory;
}

int main(int argc, char **argv) 
{
	test();
	return 0;
}