/*
 *FileName:��������ģʽ
 *Date:2018.7.23
 *Description:
 */
#include <iostream>
#include <cstdlib>
using namespace std;
/*����һ��ˮ�������๩�����ˮ��ʵ�ֺͳ��󹤳��ķ���*/
class AbstractFruit {
public:
	virtual void showFruitName() = 0;
};
/*�������һ����ˮ����������Ҫȥ�޸������κ�һ���࣬
   ��ֻ��Ҫʵ��һ����ˮ��������һ����ˮ�������༴��*/
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
/*����һ�����󹤳��࣬�������ˮ������ʵ�֣������س���ˮ����*/
class AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};
/*ʵ�ֳ��󹤳���������һ������ˮ��ָ��*/
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
	/*����������תԭ������Խӿڵı�̡���ֻ��Ҫʹ�ó��󹤳�
	  ���ָ��ͳ���ˮ�����ָ�룬ͨ����̬�����ԣ��Ϳ�����ɾ�
	  �����ҵ��*/
	AbstractFruitFactory *FruitFactory = NULL;
	AbstractFruit *fruit = NULL;
	/*������ָ�룬���Appleҵ��*/
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