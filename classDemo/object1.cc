#include <iostream>
#include <cmath>
using namespace std;


class Point{
	private:
		double px, py;
	public:
		Point(){  // default constructor, same name as object
			px = 1, py = 1;
		}
		Point(double x, double y){ // secondary constructor
			cout << "Secondary constructor used: " << endl;
			px = x, py = y;
		}

		double getx() { return px; }
		double gety() { return py; };

		void setx(double x) { px = x; };
		void sety(double y) { py = y; };

		void printPoint() {
			cout  << px << ", " << py << endl;
		}

		double distance(Point point2){
			return sqrt(pow(px-point2.getx(),2) + pow(py-point2.gety(),2)); 
		}

		double distance(double x, double y){
			return sqrt(pow(px-x,2) + pow(py-y,2)); 
		}

		double distance(Point p, bool t){
			return 7;
		}

		Point factorPoint(double f){
			Point p3(px*f, py*f);
			return p3;
		}

};


double distanceBetween(Point point1, Point point2){
	return sqrt( pow(point1.getx()-point2.getx(),2) + pow(point1.gety()-point2.gety(),2));
}


int main(){
	
	Point p1;  //instantiating an object
	p1.printPoint();

	Point p2(2, 4.6);
	p2.printPoint();


	cout << "New way, calling method within class: " << endl;
	cout << p1.distance(p2) << endl;
	cout << p1.distance(1,2) << endl;

	Point newPoint = p1.factorPoint(10);
	newPoint.printPoint();
}
