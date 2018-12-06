#include <iostream>
using namespace std;

bool the_function(int &i, int &b)
{
	cout << "i in the function before set i= " << i << endl;
	i = 5;
	b = i * 10;
	cout << "i in the function after set i= " << i << endl;
	return true;
}

int main(){
	int var = 0;
	int other = 0;
	cout << "var before function call= " << var << endl;
	bool worked = the_function(var, other);
	cout << "Did it work? " << boolalpha << worked << endl;
	cout << "var after function call= " << var << "and" << other << endl;
}
