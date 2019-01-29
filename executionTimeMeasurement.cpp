#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;
using namespace std;

int main()
{  
	const auto begin = high_resolution_clock::now();  // gets the current time in miliseconds
	cout << "Hello world!" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	const auto end = high_resolution_clock::now();
	auto time = end - begin;
	cout << "Elapsed time: " << duration<double, std::milli>(time).count() << " ms.\n";
	return 0;
}
