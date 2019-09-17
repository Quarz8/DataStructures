#include <chrono>
#include <iostream>

using namespace std::chrono;

// Recursively sum first N positive integers
int rSumN(int n)
{
    if(n <= 0) // base case
        return 0;
    return n + rSumN(n - 1); // n + recursive call with (n-1)
}

// Iteratively sums first N positivbe integers
int iSumN(int n)
{
    int sumN = 0;
    for(int i = 0; i <= n; i++)
        sumN += i;
    return sumN; // returns final sum
}

int main()
{
    /* Recursive Summation */

    int sumR = 0; // variable to hold recursive sum

    std::cout << "Recursively summing first 10,000 integers..." << std::endl;

    auto start = steady_clock::now(); // start time for recursive sum

    sumR = rSumN(10000); // Sum 10,000 integers recursively (doing much more crashes the program at runtime)

    auto finish = steady_clock::now(); // finished time for recursive sum

    // Calculate recursive run time using start and finish times
    auto run_time = duration_cast<nanoseconds>(finish - start);

    // Display results
    std::cout << "Sum of first 10,000 positive integers: " << sumR << std::endl;
    std::cout << "Recursive Run Time: " << run_time.count() << " nanoseconds\n" << std::endl;

    /* Iterative Summation */

    int sumI = 0; // variable to hold iterative sum

    std::cout << "Iteratively summing first 10,000 integers..." << std::endl;

    start = steady_clock::now(); // start time for iterative sum

    sumI = iSumN(10000); // Sum 10,000 integers iteratively

    finish = steady_clock::now(); // finished time for iterative sum

    // Calculate iterative run time using start and finish
    run_time = duration_cast<nanoseconds>(finish - start);

    // Display results
    std::cout << "Sum of first 10,000 positive integers: " << sumI << std::endl;
    std::cout << "Iterative Run Time: " << run_time.count() << " nanoseconds\n" << std::endl;
    return 0;
}
