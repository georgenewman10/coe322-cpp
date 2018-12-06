#include <iostream>
#include <random>
#include <vector>
using std::cout;
using std::vector;
using std::endl;


vector<float> makeVector(int size, float value){
	vector<float> x(size, value);
	return x;
}


int printVector(vector<float> Vector1){
	for(auto i:Vector1){
		cout << i << endl;
	}
	cout << Vector1.size() << endl;
	return 0;
}


int resetVectorToZero(vector<float> &Vector2){
	for(auto &i : Vector2) {
		i = 0;
	}
}




	
int main(){

	vector<float> myVector = makeVector(10,1.5);
	for (auto i : myVector){
		cout << i << endl;
	}

	for (auto i : makeVector(10,1.5)){
		cout << i << endl;
	}

	printVector(myVector);
	resetVectorToZero(myVector);
	printVector(myVector);
			
}

