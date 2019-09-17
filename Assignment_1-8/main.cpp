#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // Postcondition: Displays time it takes to add 100,000 random positive integers.

    // Will hold sum of the 100,000 random positive integers
    int sum;

    // initialize random seed
    srand(time(NULL));
    
    // Start timing
    int startTime = time(0);
    
    // Add 100,000 random positive integers
    for(int i = 0; i < 100000; i++) { // for 100,000 iterations
        sum += rand();
        cout << sum << endl; // Computes in less than half a second without printing...
    }

    // Find time elapsed by comparing current time to startTime
    int sumTime = time(0) - startTime;
    cout << "That took around " << sumTime << " seconds." << endl;
    return 0;
}
