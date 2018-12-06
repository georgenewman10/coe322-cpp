// George Newman, gwn266
// In class challenge 9.1, point class

#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


class Point{
	private:
		double px, py;
	public:
		Point(){  // default constructor, same name as object
			px = 1, py = 1;
		}
		Point(double x, double y){ // secondary constructor
			px = x, py = y;
		}

		double getx() { return px; }
		double gety() { return py; };
		void setx(double x) { px = x; };
		void sety(double y) { py = y; };

		void printout() {				// uses cout to display point coordinates
			cout << px << "," << py << endl;
		}

		float distance_to_origin() {		// distance to origin
			return sqrt(pow(px,2) + pow(py,2));
		}
		
		double distance(Point point2){				// distance formula between points
			return sqrt(pow(px-point2.getx(),2) + pow(py-point2.gety(),2)); 
		}
};


int main(){
	
	Point p1(3,4);  //instantiating objects
	Point p2(6,8);	
	cout << "Point 1: ";
	p1.printout();
	cout << "P1 Distance to origin: " << p1.distance_to_origin() << endl;
	cout << "Point 2: ";
	p2.printout();
	cout << "P2 Distance to origin: " << p2.distance_to_origin() << endl;

	cout << "Distance between points: " << p1.distance(p2) << endl;
}
