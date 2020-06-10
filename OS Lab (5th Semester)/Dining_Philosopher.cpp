#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include<vector>
#include <chrono>
#include <stdio.h>      
 
using namespace std;

void hold(int secs);
int availableForks;
int noPhilosophers;
bool *forks;

class Philosopher {

	private:
		enum states{
			hungry, eating, thinking
		};
		int status, state, stateChange; 

	public:
    	int sNo; 
    	void startsEating();
    	void update();
    	bool isHungry();

		Philosopher(int num){
			sNo = num;
			status = 1;
			state= 0;
		}
    	Philosopher(){
			sNo = 0;
			status = 1;	
		}
	
};

bool Philosopher::isHungry(){
	if(status==hungry){
		return true;
	}
	else{
		return false;
	}
}

void Philosopher::startsEating(){
	stateChange = rand() % 2+3; 
	cout<<"Philosopher: "<< sNo<<". Status: Eating for " <<stateChange<<" seconds!"<<endl;
	state = 0;
	status = eating;
	
}

void Philosopher::update(){
	if(status!=hungry){
		state=state+1;
	}

	if(state>=stateChange){
		state = 0;
		if(status==eating){
			stateChange = rand() % 2+3;
            cout<<"Philosopher: "<<sNo<<". Status: Thinking for " <<stateChange<<" seconds!"<<endl;
			availableForks=availableForks+2; 
			forks[sNo] = true;
			forks[(sNo + 1)%noPhilosophers] = true;
			status=thinking;
        }else if(status ==thinking){
			status=hungry;
			cout<<"Philosopher: "<< sNo <<". Status: Hungry!"<<endl;
		}
	}
}

Philosopher *philosophers;


int main () {

	int i,n=0;

	cout<<"Enter the number of Philosophers and Forks:" <<endl;
	cin>>n;
	if(n<=0){
		cout<<"Error! Invalid Input!" <<endl;
		exit(0);
	}
	n=abs(n);
	noPhilosophers=n;
	philosophers=(Philosopher *)malloc(n*sizeof(Philosopher));
	for(i=0;i<n;i++){
		philosophers[i]=Philosopher(i);
	}
	availableForks = noPhilosophers;
	forks=new bool[noPhilosophers];
	
	for(i=0;i<n;i++){
		forks[i]=true;
	}
    
	cout<<"There are "<<noPhilosophers<<" number of Philosophers and "<<availableForks<<" forks!\n\n"<<endl;
    
    int time_sec =0;
    while(time_sec<30){ 
        hold(1);
        srand(time(NULL));
		bool comp = false;
        int randomPh = rand() % n;
        int x = randomPh;
        
        
        while((availableForks>1)&&(!comp)){
            if(forks[randomPh]&&forks[(randomPh+1)%n]&&philosophers[randomPh].isHungry()){
                forks[randomPh] = false;
                forks[(randomPh+1)%n] = false;
                philosophers[randomPh].startsEating();
                availableForks = availableForks - 2;
            }
            randomPh = (randomPh+ 1)%n;
            if(randomPh==x){
                comp = true;
            }    
        }
                
        for(i=0;i<n;i++){
            philosophers[i].update();
        }
        time_sec++; 
    }
    return 0;
}


void hold(int secs)
{
    clock_t hold;
	clock_t cTime;
	cTime=clock();
    hold=cTime+ (secs * CLOCKS_PER_SEC);
    while(clock()<hold){}
}