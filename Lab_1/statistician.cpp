#include "statistician.h"

statistician::statistician() // constructor for statistician
{
    count = 0; // initialize all statistician's variables to placeholder 0
    total = 0;
    tinyest = 0;
    largest = 0;
}

void statistician::next(double r) // gives r to statistician
{
    total += r;              // adds value of r to total
    count++;                 // increases count by 1
    if(count == 0) {         // this is the first number given to statistician
        tinyest = r;         // set tinyest to r
        largest = r;         // and set largest to r
    } else if(r < tinyest) { // else if r is less than tinyest
        tinyest = r;         // set just tinyest to r
    } else if(r > largest) { // else if r is greater than largest
        largest = r;         // set largest to r
    }
}
void statistician::reset() // clears statistician
{
    count = 0; // sets to values initialed when constructor was called
    total = 0;
    tinyest = 0;
    largest = 0;
}
int statistician::length() // returns number of times next(r) function has been activated
{
    return count;
}
double statistician::sum() // returns sum of all numbers in statistician sequence
{
    return total;
}
double statistician::mean() // returns average of all numbers in statistician sequence
{
    return total / count; // total sum of numbers in sequence divided by count of numbers in sequence
}
double statistician::minimum() // returns tinyest number in stat sequence
{
    return tinyest;
}
double statistician::maximum() // returns largest number in stat sequence
{
    return largest;
}