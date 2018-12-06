// George Newman / gwn266
// In class challenge #6, fibonacci series by recursion

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int fib(int num) {			// recursive method for fibonacci sum
	if (num==0)
		return 0;
	if (num==1)
		return 1;
	return fib(num-1) + fib(num-2);
}


int main() {
	int n;
	cout << endl <<  "Enter number: ";
	cin >> n;
	cout << endl << endl;

	for (int i=1; i<n+1; i++){   // print out fibonacci number for series leading up to input number
		cout << "F(" << i << ") = " << fib(i) << endl;	// this is inefficent, I know
	}
	
	cout << endl << "Fibonacci sum from 0 through " << n << " = " << fib(n) << endl << endl;
}
