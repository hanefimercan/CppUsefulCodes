#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;
using namespace std;


int main()
{  
	high_resolution_clock::time_point begin = high_resolution_clock::now();  // gets the current time in miliseconds
	cout << "Hello world!" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	high_resolution_clock::time_point end = high_resolution_clock::now();
	auto time = end - begin; // auto becomes high_resolution_clock::time_point
	duration<double> timeMilliSeconds = duration<double, std::milli>(time);
	cout << "Elapsed time: " << timeMilliSeconds.count() << " ms.\n";
	cout << "Elapsed time: " << timeMilliSeconds.count() / 1000.0 << " sec.\n";
	return 0;
}

