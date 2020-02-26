#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include <semaphore.h>

#define FORK_CONSTANT "/fork_constant"
#define SPOON_CONSTANT "/spoon_constant"

using namespace std;

sem_t* fork_semaphore;
sem_t* spoon_semaphore;


int main()
{	
	int x;
	sem_unlink(SPOON_CONSTANT);
	sem_unlink(FORK_CONSTANT);

	int phil=0;
	int forks=0;
	int spoons=0;

	/*cout << "Enter the number of philosophers: "<<endl;
	cin >> phil;

	cout << "Enter the number of "*/ 


	
	fork_semaphore = sem_open(FORK_CONSTANT, O_CREAT,0644, 3);
	spoon_semaphore = sem_open(SPOON_CONSTANT,O_CREAT,0644,3);
	
	pid_t parent_pid = getpid();

	for(x=0 ; x<4; x++)
	{
		if(fork() == 0)
		{	
			break;		
		}
		
	}

	sem_wait(fork_semaphore);

	cout << "\nPhilosopher "<<getpid()-parent_pid+1<<" has picked a fork!"<< endl;	

	sem_wait(spoon_semaphore);

	cout << "\nPhilosopher "<<getpid()-parent_pid+1<<" has picked a spoon!"<< endl;	
	cout << "\nPhilosopher "<<getpid()-parent_pid+1<<" has started eating!"<< endl;	

	sleep(6);

	sem_post(fork_semaphore);
	cout << "\nPhilosopher "<<getpid()-parent_pid+1<<" has released a fork!"<< endl;	
	
	sem_post(spoon_semaphore);
	cout << "\nPhilosopher "<<getpid()-parent_pid+1<<" has released a spoon!"<< endl;	

	cout << "\nPhilosopher "<<getpid()-parent_pid+1<<" has stopped eating!"<< endl;	

	sleep(6);

	return 0;
}
