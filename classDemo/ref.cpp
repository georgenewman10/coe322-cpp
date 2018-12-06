#include <iostream>
using namespace std;

int main() {
	char letter = 'J';
	char &newletter = letter;
	newletter = 'Z';
	cout << letter << endl;
}
