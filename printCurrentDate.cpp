#include <ctime>
#include <iostream>
using namespace std;

void printcurrentDate()
{
    time_t t = std::time(0);   // get time now
    tm* now = std::localtime(&t);
    cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday;
}

int main() 
{
    printcurrentDate();
    cout << endl;
    return 0;
}
