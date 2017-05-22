#include <iostream>

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

		cout << "End of program" << endl;
		
		return 0;
}

