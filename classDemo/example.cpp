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






vector<int> CombineV(vector<int> A, vector<int> B){
	vector<int> C;
	C = A;
	for(auto i : B){
		C.push_back(i);
	}
	return C;
}

	
int main(){

	vector<int> vec1(5, 1);
	vector<int> vec2(10,2);

	vector<int> vec3 = CombineV(vec1, vec2);
	
	printVector();
}

