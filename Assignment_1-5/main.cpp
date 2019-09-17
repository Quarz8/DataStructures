#include <iostream>
using namespace std;

/*
 * Accepts a positive integer, N, as an input and displays the sum of the first N integers
 * i.e 1+2+3+...+N
 */
int main()
{
    // Precondition: N must be an integer >= 0
    // Postcondition: Displays sum of first N integers

    // Declare int sum and int N
    int sum;    // Will hold sum of first N integers
    int N = -1; // Integer N, will be changed by user

    while(N < 0) { // Ensures that N is not negative
        cout << "Enter a positive integer value for N: ";
        cin >> N;
    }
    int sum = 0;
    for(int i = 0; i <= N; i++) // Calculate sum of first N integers
        sum += i;

    // Outputs sum to the console
    cout << "The sum of the first " << N << " integers is " << sum << endl;
    return 0;
}
