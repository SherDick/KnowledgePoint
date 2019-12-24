/*
 *FileName:抽象工厂模式案例
 *Date:2018年7月26日14:34:38
 *Description:
 */
#include <iostream>
#include <cstdlib>
using namespace std;

/*抽象层*/
class AbstractCPU {
public:
	virtual void calculate() = 0;
};

class AbstractGraphicsCard {
public:
	virtual void display() = 0;
};

class AbstractMemory {
public:
	virtual void storage() = 0;
};

class AbstractFactory {
public:
	virtual AbstractCPU* createCPU() = 0;
	virtual AbstractGraphicsCard* createGraphicsCard() = 0;
	virtual AbstractMemory* createMemory() = 0;
};

class Computer {
public:
	Computer(AbstractCPU* cpu, AbstractGraphicsCard* card, AbstractMemory* mem) {
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}
	void work() {
		this->cpu->calculate();
		this->card->display();
		this->mem->storage();
	}
private:
	AbstractCPU* cpu;
	AbstractGraphicsCard* card;
	AbstractMemory* mem;
};

/*实现层*/
/*Intel厂商*/
class IntelCPU : public AbstractCPU {
public:
	virtual void calculate() {
		cout << "Intel CPU calculating..." << endl;
	}
};
class IntelCard : public AbstractGraphicsCard {
public:
	virtual void display() {
		cout << "Intel Card displaying..." << endl;
	}
};
class IntelMemory : public AbstractMemory {
public:
	virtual void storage() {
		cout << "Intel Memory storing..." << endl;
	}
};
class IntelFactory : public AbstractFactory {
public:
	virtual AbstractCPU* createCPU() {
		return new IntelCPU;
	}
	virtual AbstractGraphicsCard* createGraphicsCard() {
		return new IntelCard;
	}
	virtual AbstractMemory* createMemory() {
		return new IntelMemory;
	}
};

/*NVIDIA厂商*/
class NVIDIACPU : public AbstractCPU {
public:
	virtual void calculate() {
		cout << "NVIDIA CPU calculating..." << endl;
	}
};
class NVIDIACard : public AbstractGraphicsCard {
public:
	virtual void display() {
		cout << "NVIDIA Card displaying..." << endl;
	}
};
class NVIDIAMemory : public AbstractMemory {
public:
	virtual void storage() {
		cout << "NVIDIA Memory storing..." << endl;
	}
};
class NVIDIAFactory : public AbstractFactory {
public:
	virtual AbstractCPU* createCPU() {
		return new NVIDIACPU;
	}
	virtual AbstractGraphicsCard* createGraphicsCard() {
		return new NVIDIACard;
	}	
	virtual AbstractMemory* createMemory() {
		return new NVIDIAMemory;
	}
};

/*Kingston厂商*/
class KingstonCPU : public AbstractCPU {
public:
	virtual void calculate() {
		cout << "Kingston CPU calculating..." << endl;
	}
};
class KingstonCard : public AbstractGraphicsCard {
public:
	virtual void display() {
		cout << "Kingston Card displaying..." << endl;
	}
};
class KingstonMemory : public AbstractMemory {
public:
	virtual void storage() {
		cout << "Kingston Memory storing..." << endl;
	}
};
class KingstonFactory : public AbstractFactory {
public:
	virtual AbstractCPU* createCPU() {
		return new KingstonCPU;
	}
	virtual AbstractGraphicsCard* createGraphicsCard() {
		return new KingstonCard;
	}
	virtual AbstractMemory* createMemory() {
		return new KingstonMemory;
	}
};


int main(int argc, char **argv) 
{
	/*组装一个Intel系列电脑*/
	/*AbstractFactory *intelFactory = new IntelFactory;
	AbstractCPU *intelCPU = intelFactory->createCPU();
	AbstractGraphicsCard *intelCard = intelFactory->createGraphicsCard();
	AbstractMemory *intelMemory = intelFactory->createMemory();
	Computer *com = new Computer(intelCPU, intelCard, intelMemory);
	com->work();
	cout << endl;*/
	/*组装一个intel的cpu，NVIDIA的显卡，Kingston的内存的电脑*/
	AbstractFactory *intelFactory = new IntelFactory;
	AbstractFactory *NVIFactory = new NVIDIAFactory;
	AbstractFactory *KingFactory = new KingstonFactory;
	AbstractCPU *intelCPU = intelFactory->createCPU();
	AbstractGraphicsCard *NVIDIACard = NVIFactory->createGraphicsCard();
	AbstractMemory *KingstonMem = KingFactory->createMemory();
	Computer *com = new Computer(intelCPU, NVIDIACard, KingstonMem);
	com->work();

	return 0;
}