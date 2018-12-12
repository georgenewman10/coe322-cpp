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
        Person() { name = 1; }                              // default constructor, name set to 1
        Person(int a) { name = a; }                         // name each person with  a number
        
        bool getstable(){ return stable; }
        int getstatus() { return status; }   
        void infect(int n) { if (status==-100){ status = n; } }
       
        void update(){
            if (status==1) { status = -2;}
            if (status >1) { status = status-1; }
        }
        
        string status_string(){
            if (status<-99) { return "Susceptible"; }
            if (status== 0) { return "Recovered"; }         // "healthy"
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
        int p, psize, sick, r1, r2, r3, r4, r5, r6, step;   // cut some of these
        vector<Person> popvec;
    public:
        Population(){ popvec.push_back(Person(1)); }        // default constructor
        Population(int a){                                  // actual constructor we will use
            for(int i=0; i<a; i++){
                popvec.push_back(Person(i));
            }
            psize = a;
            r1 = rand() % 100;     
            r2 = rand() % 100;

            r6 = rand() % psize + 1;
            step = 1;
            p = 25;                                         // default transfer probability
        }
        
        int getstep() { return step; }
        void nextstep() { step++; }

        void set_probability_of_transfer(int a) { p = a; }  // user accessible setter function
        void random_infection() { popvec[r3].infect(5); }   // infect popvec[1] for 2 days

        void interact() {
            int count = 0;
            for(int i=0; i<psize; i++) {
                if (popvec[i].is_stable()) { continue; }
                while (count < 6){
                    r1 = rand() % 100;                      
                    r6 = rand() % psize;                    // random person
                    if (r1<p) { popvec[r6].infect(5); }     // infect this person if bad luck
                    count++;                                // add one interaction regardless of outcome
                }
            }
        }
        
        void updatePop(){
            for(int i=0; i<psize; i++){
                popvec[i].update();
            }
            step++;
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
    int n,p;
    bool flag = true;
        
    cout << "Size of population: 25" << endl;
    cout << "Probability of transfer (%): 25%" << endl;
    
    n = 50;
    p = 25;

    Population population(n);
    population.set_probability_of_transfer(p);
    population.random_infection();
    
    while (true) {
        cout << "In day " << population.getstep() << " #sick = " << population.count_infected()
        << " : " << population.popStatus() << endl;
        population.updatePop();
        if (not flag) { break; }
        if (population.count_infected()==0) {flag = false; }
        population.interact();
    }
    cout << "Disease ran its course by day " << population.getstep() << endl;
    

    return 0;
}

