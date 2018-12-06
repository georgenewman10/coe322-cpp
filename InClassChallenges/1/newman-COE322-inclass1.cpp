#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int main() {

// initialize the  variables for later use
	float a, b, c, angle1, angle2;
 
// taking input from user
	cout << "Enter side a value: \n";
	cin >> a;
	cout << "Enter side b value: \n";
	cin >> b;

// calculating hypotenuse
	c = sqrt(a*a + b*b);
	
// calculating angles
	angle1 = atan(a/b) * (180 / 3.14159265359265359);
	angle2 = acos(a/c) * (180 / 3.14159265359);

// displaying results 
	cout << "With a side a of " << a << " and a side b of " << b << endl;
	cout << "The hypotenuse is = " << c << endl;
	cout << "The angle 1 is = " << angle1 << " degrees" << endl;
	cout << "The angle 2 is = " << angle2 << " degrees" << endl;
}
