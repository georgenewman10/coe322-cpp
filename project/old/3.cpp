#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Person {
    private:
        int status=-100;
        bool stable;
    public:
        bool getstable(){ return stable; }
        int getstatus() { return status; }   
        void infect(int n) { if (status!=-2){ status = n; } }

        void update(){
            if (status==1) { status = -2;}
            if (status >1) { status = status-1; }
        }
        
        string status_string(){
            if (status<-99) { return "Susceptible"; }
            if (status== 0) { return "Recovered"; }  // this would usually be "healthy" but i changed it
            if (status==-1) { return "Recovered"; }
            if (status==-2) { return "Inoculated"; }
            if (status > 0) { return "Sick"; }
        }

        bool is_stable() {
            if (status<=0) { return true; }
            if (status >0) { return false; }
        }
};

class Population {
    private:
        int npeople;
        
    public:
        vector<Person> popvec;
        Population() { 
            npeople=10;
            vector<Person> popvec(npeople);
        }
        Population(int a) { 
            npeople=a; 
            vector<Person> popvec(npeople);
        }
            
        void random_infection(){
            popvec[5].infect(6);
        }
       
};



int main() {
    int n = 15;
    Population brenham(n);
     
    cout << brenham.popvec[5].getstatus();

/*
    Person joe; 
    int day = 1;
    joe.infect(n);
    while (not joe.is_stable()){
        cout << "On day " << day << " Joe is " << joe.status_string() 
            << " (" << joe.getstatus() << " to go)" << endl;
        day++;
        joe.update();
    }
    if (joe.is_stable()){ 
        cout << "On day " << day << " Joe is Recovered" << endl;
    };
*/

    return 0;
}

