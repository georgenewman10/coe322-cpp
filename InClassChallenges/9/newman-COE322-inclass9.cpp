// In class challenge #9
// George Newman, gwn266, 10-25-2018

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using std::cout;
using std::vector;
using std::endl;
using std::sort;

vector<float> random_vector(int length){
	vector<float> vec;
	while(vec.size()<length) {
		int r = (int)(100. * rand()/RAND_MAX);
		vec.push_back(r);
	}	
	return vec;
}

vector<float> sortFunc(vector<float> vec){
	vector<float> sorted;
	sort(vec.begin(), vec.end());
	sorted = vec;		
	return sorted;
}




int main(){
	int length = 10;

	vector<float> values = random_vector(length);
	cout << "Before sorting \n";
	for (auto i : values){
		cout << i << endl;
	}

   	vector<float> sorted = sortFunc(values);
	cout << endl << "After sorting \n";
	for (auto j : sorted){
		cout << j << endl;
	}
	cout << endl;

}
