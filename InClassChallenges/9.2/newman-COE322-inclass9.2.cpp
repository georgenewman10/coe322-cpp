// George Newman, gwn266
// In class challenge 9.2, point class

#include <iostream>
#include <cmath>
using std::cout;
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


class Line{
	private:
		double px1, px2, py1, py2;
	public:
		Line() {
			px1 = 0; py1 = 0; px2 = 1; py2 = 1;
		};
		Line(Point p1, Point p2) {
			px1 = p1.getx(); py1 = p1.gety(); px2 = p2.getx(); py2 = p2.gety();
		};
		void printout(){
			cout << "Point 1: " << px1 << "," << py1 << endl;
			cout << "Point 2: " << px2 << "," << py2 << endl;
		};
		Point midpoint(){
			
			double mx, my;
			mx = (px1+px2)/2;
			my = (py1+py2)/2;
			Point mid(mx,my);
			return mid;
		};
};

int main(){
	
	Point p1(3,4);  //instantiating points
	Point p2(6,8);
	Line L1(p1,p2);	//instantiating Line object
	Point midpoint = L1.midpoint(); // calling midpoint method, which created a Point object
	L1.printout(); 
	cout << "Midpoint coordinates: ";
	midpoint.printout(); // calling the printout method from point object, proving that midpoint is a Point object
}
