#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int main(){
	vector<int> myVector={4, 7, 3, 2, 1};
	vector<int> myVector2(3, 5);
	vector<int> myVector3(5);
	vector<int> myVector4;

	cout << "Size = " << myVector4.size() << endl;
	myVector4.push_back(10);
	cout << "Size = " << myVector4.size() << endl;
	cout << "myVector contains: " << endl;


	for (auto &i : myVector){
		cout << i << endl;
		i = i*5;
	}	
	cout << "myVector *now* contains: " << endl;


	for (auto i : myVector){
		cout << i << endl;
	}

	vector<float> col(12, 5);
	vector<vector<float>> N(5,col);
	for (auto x : N) {
		for (auto z : x) {
			cout << z << " ";
		}
		cout << endl;
	}
	
	cout << "element 5 = " << myVector[4] << endl; 
	cout << "myVector[4] = " << myVector.at(4) << endl;

}
