#include "statistician.h"
using namespace std;

// Comments are what should happen in console upon execution
int main()
{
    cout << "created instance of statistician" << endl;
    statistician test;                             // create statistician test
    cout << "Length: " << test.length() << endl;   // 0
    cout << "Minimum: " << test.minimum() << endl; // 0 (breaks precondition)
    cout << "Maximum: " << test.maximum() << endl; // 0 (breaks precondition)
    cout << "Sum: " << test.sum() << endl;         // 0
    cout << "Mean: " << test.mean() << endl;       // 0 (breaks precondition)
    cout << "next(4)" << endl;
    test.next(4);
    cout << "next(-7)" << endl;
    test.next(-7);
    cout << "next(-0.4)" << endl;
    test.next(-0.4);
    cout << "next(8)" << endl;
    test.next(8);
    cout << "Length: " << test.length() << endl;   // 4
    cout << "Minimum: " << test.minimum() << endl; // -7
    cout << "Maximum: " << test.maximum() << endl; // 8
    cout << "Sum: " << test.sum() << endl;         // 4.6
    cout << "Mean: " << test.mean() << endl;       // 1.15
    cout << "reset() function called" << endl;
    test.reset();                                  // reset test's variables to 0
    cout << "Length: " << test.length() << endl;   // 0
    cout << "Minimum: " << test.minimum() << endl; // 0 (breaks precondition)
    cout << "Maximum: " << test.maximum() << endl; // 0 (breaks precondition)
    cout << "Sum: " << test.sum() << endl;         // 0
    cout << "Mean: " << test.mean() << endl;       // 0 (breaks precondition)
    return 0;
}
