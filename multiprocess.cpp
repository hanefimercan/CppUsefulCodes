// Author : Hanefi Mercan
// Date   : 25.12.2018
// Example usage of fork() funciton for multi-processing on UNIX based systems
// Note that this code will not work on a Windows machine.



/*
fork() creates a new process by duplicating the calling process.  
The new process is referred to as the child process.  
The calling process is referred to as the parent process.
*/


#include <iostream>
#include <unistd.h>
#include <ctime>
#include<sys/wait.h>

using namespace std;
int main()
{
    srand(time(NULL));
    pid_t pid = fork();
    int rndTime1, rndTime2;
    rndTime1 = rand();
    rndTime2 = rand();
    if (pid == 0)  // child process, process id is 0
    {
        for (int i = 0; i < 5; ++i)
        {
            rndTime1 = (rand() + rndTime1) % 3 + 1;
            cout << "Child process with pid " << pid << ", at loop iteration " << i;
            cout << ", waiting " << rndTime1 << " seconds." << endl;
            sleep(rndTime1);
        }
    }
    else if (pid > 0) // parent process, process id may vary
    {
        for (int i = 0; i < 5; ++i)
        {
            rndTime2 = (rand() + rndTime2) % 3 + 1;
            cout << "Parent process with pid " << pid << ", at loop iteration " << i;
            cout << ", waiting " << rndTime2 << " seconds." << endl;
            sleep(rndTime2);
        }
    }
    else  
    {
        cout << "Something went wrong, fork() failed!" << endl;
        return 1;
    }

    cout << "** I am done, my pid is " << pid << endl;
    
    int status = 0;
    while ((wait(NULL)) > 0); // Suspends the execution of the calling (in this case parent) 
                              // process as long as a child process is alive

    return 0;
}
