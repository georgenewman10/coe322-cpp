// George Newman, gwn266
// Homework 3: triangle class with methods
// the homeword description doesn't state what the program should do, so I'll make it mimic the functionality of the program from in-class challenge number 7: It will take inputs from the user, and calculate the hypotenuse and all 3 angles.

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

class Triangle{
	private:
		float s1, s2, hyp, angle1, angle2, angle3;
	public:
		Triangle(){
			s1 = 1, s2 = 1, hyp = 1, angle1 = 1, angle2 = 1, angle3 = 90;
		};
		float gets1() { return s1; };
		float gets2() { return s2; };
		float gethyp() { return sqrt(s1*s1 + s2*s2); };
		float getangle1() { return atan(s1/s2) * (180/M_PI); };
		float getangle2() { return atan(s2/s1) * (180/M_PI); };
		float sets1(float z) { s1 = z; };
		float sets2(float x) { s2 = x; };
};

int main() {
	Triangle tri;
	float side1, side2;
	cout << "Enter side 1 length: ";
	cin >> side1;
	cout << "Enter side 2 length: ";
	cin >> side2;
	tri.sets1(side1);   // using setter function to allow user to input the size of the triangle
	tri.sets2(side2); 
	cout << "Hypotenuse length: " << tri.gethyp() << endl;    // using getters to pull info from triangle class
	cout << "Angle 1: " << tri.getangle1() << "degrees" << endl;
	cout << "Angle 2: " << tri.getangle2() << "degrees" << endl;
	cout << "Angle 3: " << 90 << " degrees" << endl;     // why not
}
