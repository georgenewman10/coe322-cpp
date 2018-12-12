#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person {
    private:
        int status;
        bool stable;
    public:
        void update(){
            status = status-1;
        }
        
        void status_string(){
            if (status==0){
                cout << "Healthy" << endl;
            }
            if (status==-1){
                cout << "Recovered" << endl;
            }
            if (status==-2){
                cout << "Inocculated" << endl;
            }
            if (status>0){
                cout << "Sick" << endl;
            }
        }
          
        void infect(int n){
            status = n;
        }

        bool is_stable(){
            if (status>0){
                stable = false;
            } else {
                stable = true;
            }
            return stable;
        }
};


int main() {
    int n = 5;
    Person joe;
    
    float bad_luck = .9;

    if (bad_luck>.5) joe.infect(n);
    
    cout << joe.is_stable() << endl;
    joe.status_string();
    joe.update();
    joe.status_string();
    joe.update();
    joe.status_string();
    joe.update();  
    joe.update();
    joe.update();
    joe.update();
    joe.status_string();
}

