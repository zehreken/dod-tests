#include <iostream>

class Big
{
	private:
		int size;
		int cachedArea;
	public:
		void setSize(int size);
		int getSize();
		int area();
};

void Big::setSize(int size)
{
	this->size = size;
}

int Big::getSize()
{
	return this->size;
}

int Big::area()
{
	if (cachedArea == 0)
	{
		cachedArea = size * size * size;
	}
	return cachedArea;
}

int main()
{
		using namespace std;

		int ints[100];
		int *ptr;
		ptr = ints;
		cout << "Address of ints: " << ptr << endl;
		
		for (int i = 0; i < 100; ++i)
		{
				ints[i] = 15;
				cout << ints[i] << endl;
		}

		Big big;
		cout << "Big size: " << big.getSize() << endl;
		big.setSize(100000);
		cout << "Big size: " << big.getSize() << endl;
		cout << "Address of big: " << &big << endl;
		cout << "Size of big: " << sizeof(big) << endl;

		cout << "End of program" << endl;
		
		return 0;
}

