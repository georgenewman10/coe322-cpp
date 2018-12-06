#include <iostream>
using namespace std;


struct coord {
	float x; 
	float y;
};


int print_coord(coord mypoint){
	cout << mypoint.x << ", " << mypoint.y << endl;
}

int reset_point(coord &mypoint){
	mypoint.x = 0;
	mypoint.y = 0;
	return 0;
}

int main() {
	coord my_point;

	my_point.x = 7.2;
	my_point.y = 1.4;
	print_coord(my_point);

	coord p2;
	p2.x = 1;
	p2.y = 17;

	print_coord(p2);
	reset_point(p2);
	print_coord(p2);

	coord myset[100];
	for (int i=0; i<100; i++){
		myset[i].x = i;
		myset[i].y = i*2;
	}

	return 0;
}
