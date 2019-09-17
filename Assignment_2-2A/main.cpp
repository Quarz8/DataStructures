#include <iostream>
using namespace std;

// Postcondition: Returns (n) factorial
int factorial(int n);

// Postcondition: Returns sum of first (n) positive integers
int f(int n);

// Postcondition: Returns number at index (index) of Fibonacci sequence
int fib(int index);

// Postcondition: Prints (message) (times) amount of times
void nPrintln(string& message, int times);

// Helper function for isPalindrome(const string& s)
bool isPalindrome(const string& s, int low, int high);

// Returns true, i.e. 1, if (s) is a palindrome
bool isPalindrome(const string& s);

// Tests recursive functions
int main()
{
    cout << "8! = " << factorial(8) << endl;                                              // Recursive factorial
    cout << "Sum of first 100 positive integers is: " << f(100) << endl;                  // Recursive sum
    cout << "Number at the 16th index of the Fibonacci sequence is: " << fib(16) << endl; // Recursive Fibonacci

    string message = "Oh baby, a triple!!! Oh yeah!"; // Message for recursive print
    nPrintln(message, 3);                             // Recursive print

    string s1 = "racecar";    // palindrome for recursive isPalindrome
    string s2 = "palindrome"; // non-palindrome for recursive isPalindrome
    cout << "\"" << s1 << "\" is a palindrome: " << isPalindrome(s1) << endl; // Recursive isPalindrome
    cout << "\"" << s2 << "\" is a palindrome: " << isPalindrome(s2) << endl; // Recursive isPalindrome

    return 0;
}

/* Implementations of recursive functions */

int factorial(int n)
{
    if(n <= 0) // base case
        return 1;
    return n * factorial(n - 1); // n * recursive call with (n-1)
}

int f(int n)
{
    if(n <= 0) // base case
        return 0;
    return n + f(n - 1); // n + recursive call with (n-1)
}

int fib(int index)
{
    if(index <= 0) // base case
        return 0;
    else if(index == 1) // base case
        return 1;
    return fib(index - 1) + fib(index - 2); // recursive calls (index-1) + (index-2)
}

void nPrintln(string& message, int times)
{
    if(times >= 1) {
        cout << message << endl;      // Print message
        nPrintln(message, times - 1); // recursive call with (times-1)
    }                                 // The base case is times <= 0
}

bool isPalindrome(const string& s, int low, int high) // helper function
{
    if(high <= low) // base case (only one or no more chars left to compare)
        return true;
    else if(s[low] != s[high]) // base case (if the two chars don't match)
        return false;
    return isPalindrome(s, low + 1, high - 1); // recursive call with (low+1) and (high-1)
}
bool isPalindrome(const string& s)
{
    return isPalindrome(s, 0, s.size() - 1); // calls on helper function
}