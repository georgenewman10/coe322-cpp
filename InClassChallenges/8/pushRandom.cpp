#include <iostream>
#include <vector>
#include <random>
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> V;
	
	int r;
	while (r != 42){
		r = (int)(43. * rand()/RAND_MAX);
		V.push_back(r);
	}

	cout << V.size() << endl;
}
