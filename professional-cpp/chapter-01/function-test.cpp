#include <iostream>

using namespace std;

void myFunction(int i, char c);

int main()
{
	myFunction(10, 'a');

	return 0;
}

void myFunction(int i, char c)
{
	cout << "the value of i is " << i << endl;
	cout << "the value of c is " << c << endl;
}
