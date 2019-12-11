/*
 *FileName:�򵥹���ģʽ
 *Date:2018.7.23
 *Description:
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//�����Ʒ
class AbstractFruit {
public:
	virtual void showFruitName() = 0;
};

//�����Ʒ
class Apple :public AbstractFruit {
public:
	virtual void showFruitName() {
		cout << "Apple" << endl;
	}
};
//�����Ʒ
class Orange : public AbstractFruit {
public:
	virtual void showFruitName() {
		cout << "orange" << endl;
	}

};
//����
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