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

class Person {
    private:
        int status=-100;
        bool stable;
        int name;
    public:
        Person() { name = 1; }                              // default constructor, name set to 1
        Person(int a) { name = a; }                         // name each person with  a number
        
        bool getstable(){ return stable; }
        int  getstatus() { return status; }
        void inoculate() { status = -2; }
        void infect(int n) { if (status==-100){ status = n; } }
       
        void update(){
            if (status==1) { status = -2;}
            if (status >1) { status = status-1; }
        }
        
        string status_string(){
            if (status<-99) { return "Susceptible"; }
            if (status== 0) { return "Recovered"; }             // "healthy"
            if (status==-1) { return "Recovered"; }
            if (status==-2) { return "Inoculated"; }
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
        int p, psize, sick, r1, r6, step, vax;                  // cut some of these
        vector<Person> popvec;
    public:
        Population(){ popvec.push_back(Person(1)); }            // default constructor
        Population(int a){                                      // actual constructor we will use
            for(int i=0; i<a; i++){
                popvec.push_back(Person(i));
            }
            psize = a;
            r1 = rand() % 100;     
            r6 = rand() % psize + 1;                            // delete the  +1
            step = 1;
        }
        
        int  getstep() { return step; }
        void nextstep() { step++; }
        void set_probability_of_transfer(int a) { p = a; }      // user accessible setter function
        
        void random_infection(){ 
            for(int i=0; i<psize; i++){
                if (not popvec[i].is_inoculated()) { 
                    popvec[i].infect(5); 
                    break;
                }
            }
        }
        
        void interact(){
            int count = 0;
            for(int i=0; i<psize; i++) {
                if (popvec[i].is_stable()) { continue; }
                while (count < 6){
                    r1 = rand() % 100;                      
                    r6 = rand() % psize;                        // random person
                    if (r1<p) { popvec[r6].infect(5); }         // infect this person if bad luck
                    count++;                                    // add one interaction regardless of outcome
                }
            }
        }
        
        void updatePop(){
            for(int i=0; i<psize; i++){
                popvec[i].update();
            }
            step++;
        }
       
        void vaccinate(int a){                                  // method to vaccinate a percentage of population
            vax = a/(100/psize);
            int count = 0;
            while(count<vax){
                r6 = rand() % psize;
                if (popvec[r6].getstatus()==-2) { continue; }
                popvec[r6].inoculate();
                count++;
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
};


int main() {
    srand (time(NULL));
    int n,p,percent;
    bool flag;
    
   
    p=25;
    percent=25;
    ofstream myfile;   
    myfile.open("results/VariablePop.txt");
    myfile << "Population sizes from 10-50" << endl;
    myfile << "Static parameters: " << endl;
    myfile << "Vaccination: " << percent << "%" << endl;
    myfile << "Transfer probability: ." << p << endl << endl;
    for(n=10; n<=50; n=n+10){                                   // different population sizes
        Population pop1(n);
        pop1.vaccinate(percent);
        pop1.set_probability_of_transfer(p);
        pop1.random_infection();
        flag = true;
        myfile << "Population size: " << n << endl;
        while (flag) {
            myfile << "Day " << setw(2) << pop1.getstep() << ": " << " the # of sick = " 
            << setw(2) << pop1.count_infected()
            << "  :  " << setw(n) << pop1.popStatus() << endl;
            pop1.updatePop();
            if (not flag) { break; }
            if (pop1.count_infected()==0) {flag = false; }
            pop1.interact();
        }
        myfile << "Disease ran its course by day " << pop1.getstep() << endl << endl << endl;
    }
    myfile.close();
    


    n = 50;
    percent = 25;
    myfile.open("results/VariableTransmitionProbability.txt");
    myfile << "Transfer probability range from 0-1" <<  endl;
    myfile << "Static parameters: " << endl;
    myfile << "Vaccination: " << percent << "%" << endl; 
    myfile << "Population: " << n << endl << endl;
    for(p=0; p<=100; p=p+10){
        n = 50;
        percent = 25;
        Population pop2(n);
        pop2.vaccinate(percent);
        pop2.set_probability_of_transfer(p);
        pop2.random_infection();
        flag = true;
        myfile << "Transfer probability: ." << p << endl;
        while (flag) {
            myfile << "Day " << setw(2) << pop2.getstep() << ": " << " the # of sick = " 
            << setw(2) << pop2.count_infected()
            << "  :  " << setw(n) << pop2.popStatus() << endl;
            pop2.updatePop();
            if (not flag) { break; }
            if (pop2.count_infected()==0) {flag = false; }
            pop2.interact();
        }
        myfile << "Disease ran its course by day " << pop2.getstep() << endl << endl << endl;
    }
    myfile.close();



    n = 50;
    p = 25;
    myfile.open("results/VariableVaccinations.txt");
    myfile << "Vaccination Percentage in range 50-100" <<  endl;
    myfile << "Static parameters: " << endl;
    myfile << "Transfer probability: ." << p << endl; 
    myfile << "Population: " << n << endl << endl;
    for(percent=50; percent<=100; percent=percent+5){
        Population pop3(n);
        pop3.vaccinate(percent);
        pop3.set_probability_of_transfer(p);
        pop3.random_infection();
        flag = true;
        myfile << "Vaccination: " << percent << "%" << endl;
        while (flag) {
            myfile << "Day " << setw(2) << pop3.getstep() << ": " << " the # of sick = " 
            << setw(2) << pop3.count_infected()
            << "  :  " << setw(n) << pop3.popStatus() << endl;
            pop3.updatePop();
            if (not flag) { break; }
            if (pop3.count_infected()==0) {flag = false; }
            pop3.interact();
        }
        myfile << "Disease ran its course by day " << pop3.getstep() << endl << endl << endl;
    }
    myfile.close();



















    
    
    return 0;
}

