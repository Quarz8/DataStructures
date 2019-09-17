// FILE: stats.cpp
// CLASS PROVIDED: statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC member functions for the statistician class:
//   void next(double r)
//     Postcondition: The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//   int length( )
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( )
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( )
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( )
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.
//   double maximum( )
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.

#ifndef STATISTICIAN_H
#define STATISTICIAN_H

#include <iostream>

class statistician
{
public:
    statistician(); // constructor
    void next(double r);
    void reset();
    int length();
    double sum();
    double mean();
    double minimum();
    double maximum();
    int count;      // How many numbers in the sequence
    double total;   // The sum of all the numbers in the sequence
    double tinyest; // The smallest number in the sequence
    double largest; // The largest number in the sequence
};

#endif // STATISTICIAN_H
