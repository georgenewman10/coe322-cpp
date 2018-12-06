//George Newman - gwn266
//in class exercise #3

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

float hypotenuse(float side1, float side2) {
	float side3;
	side3 = sqrt(side1*side1 + side2*side2);
	return side3;
}

float firstAngle(float side1, float side2) {
	float angle1;
	angle1 = atan(side1/side2) * (180 / M_PI);
	return angle1;
}

float secondAngle(float side1, float side2) {
	float angle2;
	angle2 = atan(side2/side1) * (180 / M_PI);
	return angle2;
}

int main() {

	float a, b; // initialize side lengths

	cout << "Enter side a value: \n"; //take input
	cin >> a;
	cout << "Enter side b value: \n";
	cin >> b;
	
	
	cout << "Hypotenuse length is: " << hypotenuse(a, b) << endl;
	cout << "Angle 1 is " << firstAngle(a, b) << " degrees" << endl;
	cout << "Angle 2 is " << secondAngle(a, b) << " degrees" << endl;

}
