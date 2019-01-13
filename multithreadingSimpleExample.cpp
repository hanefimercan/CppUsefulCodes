// Author : Hanefi Mercan
// Date   : 13.01.2019
// A simple example of how to create threads and usage of mutex for locking

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mut;

void threadLock(int num)  
{
	lock_guard<mutex> guard(mut);  // locks until thread leaves the function (i.e., the scope of mutex)
	for (int i = 0; i < 5; i++)
		cout << "Hi there! I am thread " << num << endl;
}

int main()
{
	thread t1(threadLock, 1);
	thread t2(threadLock, 2);
	thread t3(threadLock, 3);
	thread t4(threadLock, 4);
	thread t5(threadLock, 5);
	
	for (int i = 0; i < 5; i++)  // Main thread can still interfere prints from threads
	{                            // Because, we are not locking "cout", main is allowed to run without waiting for a lock
		cout << "Hi, I am main thread!" << endl;
	}
	cout << "Main is done" << endl;
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	return 0;
}
