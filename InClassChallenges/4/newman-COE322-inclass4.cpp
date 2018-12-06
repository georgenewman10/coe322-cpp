//George Newman - gwn266
//in class exercise #4

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

void changer(float side1, float side2, float &hypotenuse, float &angle1, float &angle2)
{
	hypotenuse = sqrt(side1*side1 + side2*side2); // changes the c value
	angle1 = atan(side1/side2) * (180 / M_PI);
	angle2 = atan(side2/side1) * (180 / M_PI);
}

int main() {

	float a, b, c; // initialize side lengths
	float A, B; // initialize the angles to be changed
	cout << "Enter side a value: \n"; //take input
	cin >> a;
	cout << "Enter side b value: \n";
	cin >> b;
	
	changer(a, b, c, A, B); // calling the change function to change variables
	cout << "Hypotenuse length is: " << c << endl;
	cout << "Angle 1 is " << A << " degrees" << endl;
	cout << "Angle 2 is " << B << " degrees" << endl;
}
