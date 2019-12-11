#include <iostream>
#include <string>
using namespace std;

class printer {
public:
	static printer *getInstance() {
		return instance;
	}
	void print(string text) {
		cout << "打印内容：" << text << endl;
		printCount++;
		cout << "今天已经打印了" << printCount << "次" << endl;
	}
private:
	printer() {}
private:
	static int printCount;
	static printer* instance;
};
int printer::printCount = 0;
printer* printer::instance = new printer;

int main(int argc, char **argv) 
{
	printer *p1 = printer::getInstance();
	p1->print("test1");

	printer *p2 = printer::getInstance();
	p2->print("test2");

	printer *p3 = printer::getInstance();
	p3->print("test3");
	return 0;
}