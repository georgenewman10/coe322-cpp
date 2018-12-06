#include <iostream>
using namespace std;

int main() {
	int myvar = 10;
	int* mypointer = &myvar;

	cout << myvar << endl;
	cout << &myvar << endl;
	cout << mypointer << endl;
	cout << &mypointer << endl;
	cout << *mypointer << endl;

	myvar = 6749;

	cout << myvar << endl;
	cout << &myvar << endl;
	cout << *mypointer << endl;

}
