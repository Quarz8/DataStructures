#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    // Precondition: Time must exist
    // Postcondition: Displays current time

    // Obtain total seconds since midnight Jan 1, 1970 GMT
    int totalSeconds = time(0);

    // Remove past whole days from totalSeconds
    totalSeconds%=86400; // 86400 seconds in a day
    
    // Compute current hour   ((total hours) % 24 hours per day)
    int currentHour = totalSeconds/3600;

    // Remove total hours from totalSeconds
    totalSeconds %= 3600;

    // Compute current minute
    int currentMinute = totalSeconds / 60; // 60 seconds in a minute

    // Remove total minutes from totalSeconds
    totalSeconds %= 60; // This leaves just the current number of seconds in totalSeconds

    // Displays results
    cout << "The current time is " << currentHour << ":" << currentMinute << ":" << totalSeconds << " GMT" << endl;
    return 0;
}