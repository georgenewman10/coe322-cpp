#include <iostream>
using namespace std;

int recurse_sum(int i) {
	if (i == 0)
		return 0;
	else
		return i + recurse_sum(i-100);
}

int main() {
	cout << recurse_sum(100);
}
