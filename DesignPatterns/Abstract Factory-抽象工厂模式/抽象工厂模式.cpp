 /*
 *FileName:抽象工厂模式
 *Date:2018.7.24
 *Description:
 */
#include <iostream>
#include <cstdlib>
using namespace std;

/*抽象苹果类，供具体产地苹果实现*/
class AbstractApple {
public:
	virtual void showName() = 0;
};
class ChinaApple : public AbstractApple {
public:
	virtual void showName() {
		cout << "China Apple" << endl;
	}
};
class USAApple : public AbstractApple {
public:
	virtual void showName() {
		cout << "USA Apple" << endl;
	}
};
class JapanApple : public AbstractApple {
public:
	virtual void showName() {
		cout << "Japan Apple" << endl;
	}
};

/*抽象香蕉类，供具体产地香蕉实现*/
class AbstractBanana {
public:
	virtual void showName() = 0;
};
class ChinaBanana : public AbstractBanana {
public:
	virtual void showName() {
		cout << "China Banana" << endl;
	}
};
class USABanaa : public AbstractBanana {
public:
	virtual void showName() {
		cout << "USA Banana" << endl;
	}
};
class JapanBanana : public AbstractBanana {
public:
	virtual void showName() {
		cout << "Japan Banana" << endl;
	}
};

/*抽象桔子类，供具体产地桔子实现*/
class AbstractOrange {
public:
	virtual void showName() = 0;
};
class ChinaOrange : public AbstractOrange {
public:
	virtual void showName() {
		cout << "China Orange" << endl;
	}
};
class USAOrange : public AbstractOrange {
public:
	virtual void showName() {
		cout << "USA Orange" << endl;
	}
};
class JapanOrange : public AbstractOrange {
public:
	virtual void showName() {
		cout << "Japan Orange" << endl;
	}
};

/*抽象工厂类，供具体产品族的工厂实现*/
class AbstractFactory {
public:
	virtual AbstractApple* createApple() = 0;
	virtual AbstractBanana* createBanana() = 0;
	virtual AbstractOrange* createOrange() = 0;
};
class ChinaFactory : public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new ChinaApple;
	}
	virtual AbstractBanana* createBanana() {
		return new ChinaBanana;
	}
	virtual AbstractOrange* createOrange() {
		return new ChinaOrange;
	}
};
class USAFactory : public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new USAApple;
	}
	virtual AbstractBanana* createBanana() {
		return new USABanaa;
	}
	virtual AbstractOrange* createOrange() {
		return new USAOrange;
	}
};
class JapanFactory : public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* createBanana() {
		return new JapanBanana;
	}
	virtual AbstractOrange* createOrange() {
		return new JapanOrange;
	}
};

void test() {
	AbstractFactory *factory = NULL;
	AbstractApple *apple = NULL;
	AbstractBanana *banana = NULL;
	AbstractOrange *orange = NULL;
	/*中国的产地*/
	factory = new ChinaFactory;
	/*生产苹果、香蕉、桔子*/
	apple = factory->createApple();
	banana = factory->createBanana();
	orange = factory->createOrange();
	apple->showName();
	banana->showName();
	orange->showName();

	delete orange;
	delete banana;
	delete apple;
	delete factory;
}

int main(int argc, char **argv) 
{
	test();
	return 0;
}


