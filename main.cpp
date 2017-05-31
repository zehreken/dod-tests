#include <iostream>
#include <stack>

class Big
{
	private:
		int size;
		int test[262144]; // 1 MB size array
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

int main()
{
		using namespace std;
		
		int bigsSize = 1000;
		Big* bigs = new Big[bigsSize];
		
		Big big;
		cout << "Big size: " << big.getSize() << endl;
		big.setSize(1000);
		cout << "Big size: " << big.getSize() << endl;
		cout << "Address of big: " << &big << endl;
		cout << "Size of big: " << sizeof(big) << endl;
		cout << "Size of big(KB): " << sizeof(big) / 1024 << endl;
		cout << "Size of bigs: " << sizeof(*bigs) * bigsSize << endl;

		cout << "End of program" << endl;
		
		return 0;
}

