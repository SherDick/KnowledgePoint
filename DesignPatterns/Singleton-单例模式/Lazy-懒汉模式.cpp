class singleton {
public:
	static singleton* getInstance() {
		if (instance == NULL) {
			instance = new singleton;
		}
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
singleton* singleton::instance = NULL;

int main(int argc, char **argv) 
{
	cout << "main" << endl;
	singleton *sig = singleton::getInstance();
	return 0;
}