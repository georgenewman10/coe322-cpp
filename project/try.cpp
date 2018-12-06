#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person {
    private:
		    int status = 0; // healthy = 0, recovered = -1, inocculated = -2;
    public:
        void update(){
            status = status - 1;
          


        }; // happens once per day  

    		string status_string(){ 
            string status_string;
  	        if (status = 0) status_string = "Healthy";
		        if (status = -1) status_string = "Recovered";
		        if (status = -2) status_string = "Inocculated";
		        if (status > 0) status_string = "Sick";
		        return status_string; 
	      }
      
	      void infect(int n){ 
        status = n;
        }	

		    bool is_stable(){
        bool stable;
        if (status = 0) stable = true;
			  if (status = -1) stable = true;
			  if (status = -2) stable = true;
			  if (status > 0) stable = false;
		    return stable;
		    }
};

int main() {
	  int n = 5;
	  Person joe;
	
    float bad_luck = (float) rand()/(float)RAND_MAX;
    bad_luck = .4;

	  if (bad_luck>.50) joe.infect(n);
	  cout << bad_luck << endl;
	  for(int i=n; i>0; i--){
		  cout << "On day " << n << ", Joe is " << joe.status_string() << endl;
		  joe.update();
	  }

	  cout << joe.is_stable() << endl;
  
	  return 0;
}
