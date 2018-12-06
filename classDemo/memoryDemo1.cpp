#include <iostream>
using namespace std;

int main(){

	int i;
	cout << "Enter size of array: ";
	cin >> i;

	int array1[10] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10};
	
	for (int i=0; i<10; i++) {
		cin >> array1[i];
		cout << "element " << i << " = " << array1[i] << endl;
	}


	for(int i=0; i<10; i++){
		cout << "Element " << i+1 << " = " << array1[i] << " " << endl;
	}

	

	cout << *(array1) << endl;		// do for cipher. make array of chars
	cout << *(array1+1) << endl;	// then do this. DONT GO PAST END OF ARRAY
	return 0;
}
