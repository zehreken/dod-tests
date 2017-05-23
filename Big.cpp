#include <iostream>

class Big
{
	private:
		char name[1000];
		int size;
	public:
		void setName(char name[1000]);
		void setSize(int size);
		char getName();
		int getSize();
} big;

/*
void Big::setName(char name[1000])
{
	this->name = name;
}
*/

void Big::setSize(int size)
{
	this->size = size;
}

/*
char Big::getName()
{
	return name;
}
*/

int Big::getSize()
{
	return size;
}
