#include <iostream>
using namespace std;

class AbstractResult {
public:
	virtual double getOperResult(double num1 = 0, double num2 = 0) = 0;
};

class Add :public AbstractResult {
public:
	virtual double getOperResult(double num1 = 0, double num2 = 0) {
		return num1 + num2;
	}
};
class Sub : public AbstractResult {
public:
	virtual double getOperResult(double num1 = 0, double num2 = 0) {
		return num1 - num2;
	}
};

class AbstractFactory {
public:
	virtual AbstractResult* createOper() = 0;
};
class AddFactory : public AbstractFactory {
public:
	virtual AbstractResult* createOper() {
		return new Add;
	}
};
class SubFactory : public AbstractFactory {
public:
	virtual AbstractResult* createOper() {
		return new Sub;
	}
};

void test() {
	AbstractFactory *factory = NULL;
	AbstractResult *result = NULL;
	factory = new AddFactory;
	result = factory->createOper();
	cout << result->getOperResult(1, 2) << endl;
	delete factory;
	factory = new SubFactory;
	result = factory->createOper();
	cout << result->getOperResult(1, 2) << endl;
	delete factory;
	factory = NULL;
}

int main() {
	test();
	system("pause");
}