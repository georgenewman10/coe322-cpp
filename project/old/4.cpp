#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Person {
    private:
        int status=-100;
        bool stable;
        int name;
        
    public:
        Person() { name = 1; }   // default constructor, name set to 1
        Person(int a) { name = a; } // because I'm adding to population in a loop, I give each person a number
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
        int p, psize, sick, r1, r2, r3;
        vector<Person> popvec;
        
    public:
        Population(){ popvec.push_back(Person(1)); } // default constructor
        Population(int a){                           // actual constructor we will use
            for(int i=0; i<a; i++){
                popvec.push_back(Person(i));
            }
            psize = a;
            r1 = rand() % 100;     
            r2 = rand() % 100;
            r3 = rand() % psize + 1;
        }

        void set_probability_of_transfer(int a) { p = a; }

        void infect_neighbor() {
            for(int i=0; i<psize; i++){
                if (not popvec[i].is_stable()){
                    if (r1<p) {
                        popvec[i-1].infect(5);
                    }
                    if (r2<p) { 
                        popvec[i+1].infect(5);
                    }
                }
            }
        }

        void random_infection(){ 
            int r = rand() % psize + 1;
            popvec[r3].infect(5);  // infect popvec[1] for 2 days
        }

        void updatePop(){
            for(int i=0; i<psize; i++){
                popvec[i].update();
            }
        }
       
        int count_infected(){
            sick = 0;
            for(int i=0; i<psize; i++){
                if (not popvec[i].is_stable()) { sick = sick + 1; }
            }
            return sick;
        }

                    
        
        
        string popStatus(){
            string popstring;
            for(int i=0; i<psize; i++){
                if (popvec[i].getstatus() == -100 )  {
                    popstring.append("?");
                } else if (popvec[i].getstatus() > 0 )  {
                    popstring.append("+");
                } else if (popvec[i].getstatus() <=0 )  {
                    popstring.append("-"); 
                }
            }
            return popstring;
        }


        vector<Person> getVector() { return popvec; } // unnecessary 
};



int main() {
    srand (time(NULL));
    int day=1,n,p;
    bool flag = true;
        
    cout << "Size of population: ";
    cin >> n;
    cout << "Probability of transfer (%): ";
    cin >> p;

    Population population(n);
    population.set_probability_of_transfer(p);
    population.random_infection();
    


    while (true) {
        cout << "In day " << day << " #sick = " << population.count_infected() 
        << " :  " << population.popStatus() << endl;
        population.updatePop();
        if (not flag) { break; }
        if (population.count_infected()==0) { flag = false; }
        day++;
        population.infect_neighbor();
    }   
    cout << "Disease ran its course by day " << day << endl;
    
    
















    vector<Person> a = population.getVector(); // this is only needed for testing purposes



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

