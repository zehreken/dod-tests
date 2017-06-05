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
		float getSizeInKB();
		float getSizeInMB();
};

void Big::setActor(int actor)
{
	this->actor = actor;
}

int Big::getActor()
{
	return this->actor;
}

float Big::getSizeInKB()
{
	return sizeof(Big) / 1024.f;
}

float Big::getSizeInMB()
{
	return sizeof(Big) / (1024.f * 1024.f);
}

class Small
{
	private:
		int actor;
	public:
		void setActor(int size);
		int getActor();
		float getSizeInKB();
		float getSizeInMB();
};

void Small::setActor(int actor)
{
	this->actor = actor;
}

int Small::getActor()
{
	return this->actor;
}

float Small::getSizeInKB()
{
	return sizeof(Small) / 1024.f;
}

float Small::getSizeInMB()
{
	return sizeof(Small) / (1024.f * 1024.f);
}

int main()
{
	using namespace std;
	
	const int SIZE = 50000;
	
	Big* bigs = new Big[SIZE];
	clock_t t1, t2;
	t1 = clock();
	for (int i = 0; i < SIZE; i++)
	{
		bigs[i].setActor(i);
	}
	t2 = clock();
	float diffBig = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
	cout << "Running time for bigs: " << diffBig << endl;
	cout << "Size of big(KB): " << bigs[0].getSizeInKB() << endl;
	cout << "Size of bigs(KB): " << bigs[0].getSizeInKB() * SIZE << endl;
	cout << "Address of bigs: " << &bigs << endl;
	
	// ==========
	
	Small* smalls = new Small[SIZE];
	clock_t t3, t4;
	t3 = clock();
	for (int i = 0; i < SIZE; i++)
	{
		smalls[i].setActor(i);
	}
	t4 = clock();
	float diffSmall = ((float)t4 - (float)t3) / CLOCKS_PER_SEC;
	cout << "\nRunning time for smalls: " << diffSmall << endl;
	cout << "Size of small(KB): " << smalls[0].getSizeInKB() << endl;
	cout << "Size of smalls(KB): " << smalls[0].getSizeInKB() * SIZE << endl;
	cout << "Address of smalls: " << &smalls << endl;

	cout << "Result: " << (diffBig / diffSmall) << " times faster" << endl;

	cout << "End of program" << endl;
	
	return 0;
}

