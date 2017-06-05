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
	return sizeof(Big) / (1024 * 1024);
}

class Small
{
	private:
		int actor;
	public:
		void setActor(int size);
		int getActor();
		int getSizeInKB();
		int getSizeInMB();
};

void Small::setActor(int actor)
{
	this->actor = actor;
}

int Small::getActor()
{
	return this->actor;
}

int Small::getSizeInKB()
{
	return sizeof(Small) / 1024;
}

int Small::getSizeInMB()
{
	return sizeof(Small) / (1024 * 1024);
}

int main()
{
	using namespace std;
	
	const int SIZE = 10240;
	
	Big* bigs = new Big[SIZE];
	clock_t t1, t2;
	t1 = clock();
	for (int i = 0; i < SIZE; i++)
	{
		bigs[i].setActor(i);
	}
	t2 = clock();
	float diff = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
	cout << "Running time: " << diff << endl;
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
	diff = ((float)t4 - (float)t3) / CLOCKS_PER_SEC;
	cout << "Running time: " << diff << endl;
	cout << "Address of smalls: " << &smalls << endl;

	cout << "End of program" << endl;
	
	return 0;
}

