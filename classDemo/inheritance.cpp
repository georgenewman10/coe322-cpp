#include <iostream>
using namespace std;

class Rectangle {
	protected:
		double l,h;
	public:
		Rectangle(){
		};
		Rectangle(double length, double height) {
			l = length; h = height;
		};
		double getLength() { return l; };
		double getHeight() { return h; };
		void setlength(double length) { l = length; };
		void setHeight(double height) { h = height; };
		double area() { return l*h; };
		

		int printSummary(){
			cout << "Rectangle summary: " << endl;
			cout << "Length: " << l << endl;
			cout << "Height: " << h << endl;
			cout << "Area: " << area() << endl << endl;
		}
};

class Square : Rectangle {
	public:
		Square() { };
		Square(double side) : Rectangle(side, side){ };
		void setlength(double side){
			l = side; 
			h = side;
		}
};


int main() {
	Rectangle myR(100,50);
	myR.printSummary();

	Rectangle mySquare(100,100);
	mySquare.printSummary();
	
	Square myS1(100);
	myS1.printSummary();

	Square myS2;
	myS2.setlength(100);
	myS2.printSummary();
}
