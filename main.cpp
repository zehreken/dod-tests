#include <iostream>
#include <stack>

class Big
{
	private:
		int actor;
		int clutter[262144]; // (1MB - 8b) array makes sure that sizeof big is exatly 1MB
	public:
		void setActor(int size);
		int getActor();
		int getSizeInKB();
		int getSizeInMB();
};

void Big::setActor(int actor)
{
	this->actor = actor;
}

int Big::getActor()
{
	return this->actor;
}

int Big::getSizeInKB()
{
	return sizeof(Big) / 1024;
}

int Big::getSizeInMB()
{
	return sizeof(Big) / 1024 / 1024;
}

int main()
{
		using namespace std;
		
		const int bigCount = 1024;
		Big* bigs = new Big[bigCount];
		
		Big big;
		cout << "Size of Big(KB): " << big.getSizeInKB() << endl;
		cout << "Size of Big(MB): " << big.getSizeInMB() << endl;
		big.setActor(1000);
		cout << "Address of big: " << &big << endl;

		cout << "End of program" << endl;
		
		return 0;
}

