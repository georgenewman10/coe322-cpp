#include <iostream>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;

int main() {
	srand (time(NULL));
	int heads = 0;
	int tails = 0;
	
	for(int i=0; i<1000000; i++){
		int rand();
		int random_number = rand();
		if (random_number % 2 == 0) {
			cout << "You flipped heads" << endl;
			heads++;
		}
		else {
			cout << "You flipped tails" << endl;
			tails++;
		}
	}

	cout << "Total number of heads: " << heads << endl;
	cout << "Total number of tails: " << tails << endl;
}
