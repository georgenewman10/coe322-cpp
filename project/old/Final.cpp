// George Newman, gwn266 - Final C++ project

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::setw;
using std::ios;

class Person {
    private:
        int status=-100;
        bool stable;
        int name;
    public:
        Person()      { name = 1; }                              // default constructor, name set to 1
        Person(int a) { name = a; }                              // name each person with  a number
        
        bool getstable()   { return stable; }
        int  getstatus()   { return status; }
        void inoculate()   { status = -2; }
        void infect(int n) { if (status==-100){ status = n; } }
       
        void update(){
            if (status==1) { status = -3;}
            if (status >1) { status = status-1; }
        }
        
        string status_string(){
            if (status<-99) { return "Susceptible"; }
            if (status== 0) { return "Recovered";  }             // "healthy"
            if (status==-1) { return "Recovered";  }
            if (status==-2) { return "Inoculated";  } 
            if (status==-3) { return "Inoculated";  }
            if (status > 0) { return "Sick"; }
        }
        
        bool is_stable() {
            if (status<=0) { return true;  }
            if (status >0) { return false; }
        }

        bool is_inoculated() {
            if (status==-2) { return true;  }
            if (status!=-2) { return false; }
        }
};

class Population {
    private:
        int p,psize,r1,r2,step, sickdays, interactions;                       
        vector<Person> populationVector;
    public:
        Population(){ populationVector.push_back(Person(1)); }            // default constructor
        Population(int a){                                      // constructor we will use
            for(int i=0; i<a; i++){
                populationVector.push_back(Person(i));
            }
            psize = a;
            r1 = rand() % 100;
            r2 = rand() % psize + 1;                            
            step = 1;
        }
        
        int  getstep() { return step; }
        void nextstep() { step++; }

        void set_probability_of_transfer(int a) { p = a; }      // user accessible setter functions
        void set_sickdays(int a) { sickdays = a; }
        void set_interactions(int a) { interactions = a; }


        void random_infection(){ 
            for(int i=0; i<psize; i++){
                if (not populationVector[i].is_inoculated()) { 
                    populationVector[i].infect(sickdays); 
                    break;
                }
            }
        }
        
        void interact(){
            int count = 0;
            for(int i=0; i<psize; i++) {
                if (populationVector[i].is_stable()) { continue; }
                while (count < interactions){
                    r1 = rand() % 100;                      
                    r2 = rand() % psize;                                        // random person
                    if (r1<p) { populationVector[r2].infect(sickdays); }        // infect this person if bad luck
                    count++;                                         // add one interaction regardless of outcome
                }
            }
        }
        
        void updatePop(){
            for(int i=0; i<psize; i++){
                populationVector[i].update();
            }
            step++;
        }
       
        void vaccinate(int a){                            // method to vaccinate a percentage of population
            int vax = a/(100/psize);
            int count = 0;
            while(count<vax){
                r2 = rand() % psize;
                if (populationVector[r2].getstatus()==-2) { continue; }
                populationVector[r2].inoculate();
                count++;
            }
        }

        int count_infected(){
            int sick = 0;
            for(int i=0; i<psize; i++){
                if (not populationVector[i].is_stable()) { sick = sick + 1; }
            }
            return sick;
        }

        int count_affected(){
            int affected=0;
            for(int i=0; i<psize; i++){
                if (populationVector[i].getstatus()==-3){
                    affected++;
                }
            }
            return affected;
        }

        string popStatus(){
            string popstring;
            for(int i=0; i<psize; i++){
                if (populationVector[i].getstatus() == -100 )  {
                    popstring.append("?");
                } else if (populationVector[i].getstatus() > 0 ) {
                    popstring.append("+");
                } else if (populationVector[i].getstatus()==-2 ) {
                    popstring.append("-"); 
                } else if (populationVector[i].getstatus()==-3 ) {
                    popstring.append("-");
                }
            }
            return popstring;
        }
};


void generateDiseaseInfo(int n, int p, int infectionLength, int interactionsPerDay, bool visual) {
    bool flag;
    int percent, affected;
    ofstream f;
    f.open("results/DiseasePropagationData.txt");
    f << "Disease Propagation Model " << endl << endl;
    f << "Constant, user defined parameters: " << endl;
    f << "Population = " << n << endl;
    f << "Transfer probability = ." << p << endl; 
    f << "Infection length = " << infectionLength << " days" << endl;
    f << "Interactions per day = " << interactionsPerDay << endl << endl;
    f << "Legend: " << endl << "(+) Infected" << endl << "(-) Inoculated" 
    << endl << "(?) Susceptible" << endl << endl;

    for(percent=0; percent<=100; percent=percent+5){
        Population pop(n);
        pop.vaccinate(percent);
        pop.set_probability_of_transfer(p);
        pop.set_sickdays(infectionLength);
        pop.set_interactions(interactionsPerDay);
        pop.random_infection();
        flag = true;
        f << "Vaccination: " << percent << "%" << endl;
        while (flag) {
            if (visual){
                f << "Day " << setw(2) << pop.getstep() << ": " << " the # of sick = " 
                << setw(2) << pop.count_infected()
                << "  :  " << setw(n) << pop.popStatus() << endl;
            }
            if (not flag) { break; }
            if (pop.count_infected()==0) {flag = false; }
            pop.updatePop();
            pop.interact();
        }
        f << "Disease ran its course by day " << pop.getstep()-1 << ". Total affected: " << 
        pop.count_affected() << ". Unaffected: " << n-pop.count_affected() << endl << endl << endl;
    }
    f.close();
}


int main() {
    srand (time(NULL));
    int n,p,days,interactions;
    bool flag,vis;
    char visual;


    cout << endl << endl << "Welcome to your disease propagation model! Let's start with some parameters. "
    << endl;
    cout << "Enter the population size (0-50): ";
    cin >> n;
    cout << "Enter the probability (%) of disease transfer (1-100): ";
    cin >> p;
    cout << "Enter how long the disease lasts (# of days): ";
    cin >> days;
    cout << "Enter the number of interactions each person has per day: ";
    cin >> interactions;
    cout << "Would you like to see a visual representation of the disease path? (y/n): ";
    cin >> visual;
    if (visual=='y') { vis=true; }
    if (visual=='n') { vis=false; }


    generateDiseaseInfo(n,p,days,interactions,vis);
    cout << "Your disease simulation has been run!" << endl;

    return 0;
}

