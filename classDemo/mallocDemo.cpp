#include <iostream>
using namespace std;

struct roomTemp {
	float x=0;
	float y=0;
	float z=0;
	float temp=0;

	*roomTemp nextTemp;
};


int main() {
	
	int t = 100;
	roomTemp* rt;

	for (int i=0; i<10; i++) {
		rt = (roomTemp*)malloc(sizeof(roomTemp));
		cout << rt << endl;
	}

}
