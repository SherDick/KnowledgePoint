/*饿汉式-------在编译期间就已经确定该对象的唯一实例*/
class singleton {
public:
	static singleton* getInstance() {
		return instance;
	}
private:
	/*不让类的外部再创建实例*/
	singleton() {
		cout << "singleton" << endl;
	}
private:
	/*指向本类唯一实例的指针*/
	static singleton *instance;
};

singleton* singleton::instance = new singleton;

int main(int argc, char **argv) 
{
	cout << "main" << endl;
	singleton *sig1 = singleton::getInstance();
	singleton *sig2 = singleton::getInstance();
	if (sig1 == sig2) {
		cout << "The same instance" << endl;
	}
	return 0;
}