#include <iostream>
#include <time.h>
#include <stack>

class Big
{
	private:
		int actor; // 32b primitive type
		int clutter[262144]; // (1MB - 32b) array makes sure that sizeof big is exatly 1MB
	public:
		void setActor(int size);
		int getActor();
		float getSizeInKB();
		float getSizeInMB();
		void fillClutter();
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

void Big::fillClutter()
{
	for (int i = 0; i < 262144; i++)
	{
		this->clutter[i] = 0xffffffff;
	}
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

using namespace std;

float createAndLoopBigs(int size)
{
	Big* bigs = new Big[size];
	cout << "Address of bigs: " << bigs << endl;

	for (int i = 0; i < size; i++)
	{
		bigs[i].fillClutter();
	}
	
	clock_t t1, t2;
	t1 = clock();
	for (int i = 0; i < size; i++)
	{
		bigs[i].setActor(i);
	}
	t2 = clock();
	float time = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;

	return time;
}

float createAndLoopSmalls(int size)
{
	Small* smalls = new Small[size];
	cout << "Address of smalls: " << smalls << endl;
	
	clock_t t1, t2;
	t1 = clock();
	for (int i = 0; i < size; i++)
	{
		smalls[i].setActor(i);
	}
	t2 = clock();
	float time = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;

	return time;
}

int main()
{
	const int SIZE = 500	0;
	float sum;
	for (int i = 0; i < 1; i++)
	{
		sum += createAndLoopBigs(SIZE) / createAndLoopSmalls(SIZE);
	}

	cout << "Average: " << sum / 1 << endl;

	return 0;
}

