// George Newman
// in class challenge #7, triangle solver with structs

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

struct triangle
{
	float s1;
	float s2;
	float hyp;
	float angle1;
	float angle2;
	float angle3;
};

int calculate(triangle &tri){
	tri.hyp = sqrt(tri.s1*tri.s1 + tri.s2*tri.s2);
	tri.angle1 = atan(tri.s1/tri.s2) * (180 / M_PI);
	tri.angle2 = atan(tri.s2/tri.s1) * (180 / M_PI);
	tri.angle3 = 90; 
}


int main(){
	triangle t1, t2;

	cout << "Triangle 1 side 1: ";
	cin >> t1.s1;
	cout << "Triangle 1 side 2: ";
	cin >> t1.s2;
	cout << "Triangle 2 side 1: ";
	cin >> t2.s1;
	cout << "Triangle 2 side 2: ";
	cin >> t2.s2;
	calculate(t1);
	calculate(t2);
	
	cout << endl << "Triangle 1 info: " << endl;
	cout << "Hypotenuse = " << t1.hyp << endl;
	cout << "Angle 1 = " << t1.angle1 << endl;
	cout << "Angle 2 = " << t1.angle2 << endl;
	cout << "Angle 3 = " << t1.angle3 << endl;

	
	cout << endl << "Triangle 2 info: " << endl;
	cout << "Hypotenuse = " << t2.hyp << endl;
	cout << "Angle 1 = " << t2.angle1 << endl;
	cout << "Angle 2 = " << t2.angle2 << endl;
	cout << "Angle 3 = " << t2.angle3 << endl;
	
	return 0;
}

