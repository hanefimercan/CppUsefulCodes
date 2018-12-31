#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
using namespace std;

// Try to get lock
int tryGetLock(char const *lockName, string processName)
{
	mode_t m = umask(0);
	cout << processName << ": Trying to acquire the lock..." << endl;
	int fd = open(lockName, O_RDWR | O_CREAT, 0666);  // Try to get lock. Return its file descriptor or -1 if failed.
	umask(m);
	while (fd >= 0 && flock(fd, LOCK_EX | LOCK_NB) < 0)
	{
		sleep(1);
		close(fd);
		fd = open(lockName, O_RDWR | O_CREAT, 0666); // Try again to get lock.
		umask(m);
	}
	cout << processName << ": Lock has been acquired." << endl;
	return fd;
}

// Release the lock obtained with tryGetLock( lockName ).
void releaseLock(int fd, string processName)
{
	close(fd);
	cout << processName << ": Lock has been released." << endl;
}

int main()
{
	string processName;
	char *lockFileName = "tempLock";
	pid_t pid = fork();

	if (pid == 0)  // child process, process id is 0
	{
		processName = "CHILD";
		cout << processName << ": Waiting for 3 seconds..." << endl;
		sleep(3);
		int lock = tryGetLock(lockFileName, processName);
		sleep(5);
		releaseLock(lock, processName);

		
	}
	else // parent process, process id may vary
	{
		processName = "PARENT";
		cout << processName << ": Waiting for 5 seconds..." << endl;
		sleep(5);
		int lock = tryGetLock(lockFileName, processName);
		sleep(3);
		releaseLock(lock, processName);
	}

	return 0;
}
