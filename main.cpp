#include <iostream>
#include <time.h>
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

		clock_t t1,t2;
		t1=clock();
		
		for (int i = 0; i < bigCount; i++)
		{
			bigs[i].setActor(i);
		}
		
		/*
		for (int i = 0; i < bigCount; i++)
		{
			cout << "Actor: " << bigs[i].getActor() << "\t Size of Big(KB): " << bigs[i].getSizeInKB() << endl;
		}
		*/
				
		t2=clock();
		float diff = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
		cout << "Running time: " << diff << endl;

		
		cout << "Address of bigs: " << &bigs << endl;
		cout << "End of program" << endl;
		
		return 0;
}

