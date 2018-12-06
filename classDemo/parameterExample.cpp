#include <iostream>
using namespace std;

float eq_line (int x1, float m1, int b1);

int main() {
	int point_x = 2, yintercept_b = 1;
	float slope_m = .3, point_y;
	point_y = eq_line(point_x, slope_m, yintercept_b);
	cout << point_y << " = (" << slope_m << "*" << point_x << ") + " << yintercept_b << endl;
}

float eq_line (int x1, float m1, int b1) {
	float y1;
	y1 = m1 * x1 + b1;
	return y1;
	
}
