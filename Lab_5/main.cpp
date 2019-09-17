#include <chrono>   // used to time loops
#include <iostream> // changed to standard instead of <iosteam.h>
#include <vector>   // allow use of vectors

using namespace std; // added for cout and endl

static const int N = 10000; // increased to 10,000 from 1,000
typedef bool arrayType;     // change to test different types of arrays

int main()
{
    int i;                           // for loop initialization
    arrayType a[N];                  // static array a
    //arrayType* a = new arrayType[N]; // dynamic array
    //vector<arrayType> a(N);          // vector of size N

    chrono::nanoseconds runtime1;                          // will hold runtime of first 2 for loops
    chrono::nanoseconds runtime2 = chrono::nanoseconds(0); // will hold runtime of third for loop. initialized to 0
    auto start1 = chrono::steady_clock::now();             // start time for first 2 for loops
    for(i = 2; i < N; i++)   // first for loop. for each value in a from index 2 through N-1...
        a[i] = 1;            // sets all values in a to 1 for indices 2 through N-1
    for(i = 2; i < N; i++) { // second for loop. for each value in a from index 2 through N-1...
        if(a[i]) {           // if a[i] is not 0...
            auto start2 = chrono::steady_clock::now();  // start time of third loop
            for(int j = i; j * i < N; j++)              // third for loop.
                a[i * j] = 0;                           // indices that are prime numbers have their value set to 0
            auto finish2 = chrono::steady_clock::now(); // end time of third loop
            runtime2 += chrono::nanoseconds(finish2 - start2); // add for loop's duration to runtime2
        }
    }
    auto finish1 = chrono::steady_clock::now();       // finished time first 2 loops
    runtime1 = chrono::nanoseconds(finish1 - start1); // duration of first 2 loops

    int printCount = 0;            // counts how many numbers are printed
    for(i = 2; i < N; i++)         // for each value in a from index 2 through N-1...
        if(a[i]) {                 // if a[i] is not 0
            cout << " " << i;      // displays i
            printCount++;          // Increments printCount after i is displayed
            if(printCount == 10) { // if printCount is 10
                cout << endl;      // go to new line
                printCount = 0;    // and reset printCount to 0
            }
        }
    cout << endl;
    // Display runtimes for first two loops
    cout << "Runtime of first two for loops: " << runtime1.count() << " ns" << endl;
    cout << "Runtime of third for loop: " << runtime2.count() << " ns" << endl;
}