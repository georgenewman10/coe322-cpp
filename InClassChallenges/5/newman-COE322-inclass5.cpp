// George Newman / gwn266
// In class challenge # 5, recursive sum of squares

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int sumOfSquares(int s) {
	if(s==1)
		return 1;
	else
		return (s*s) + sumOfSquares(s-1);
		
}

int main() {
	cout << "Sum of squares 1 through 100: " << sumOfSquares(100) << endl;
}
