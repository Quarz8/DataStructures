/////////////////// Program 2.2

#include <iostream>
using namespace std;

void m(int&, int []); // changed 'int' parameter to 'int&' (see line 27)
void p(int list[], int arraySize) // changed 'const int list[]' to 'int list[]'
{ // This is because list[] is clearly meant to be changed.
list[0] = 100; 
}

// Tests m(int&, int []) function
int main()
{
int x = 1; 
int y[10]; 
y[0] = 1;

m(x, y); 

cout << "x is " << x << endl;
cout << "y[0] is " << y[0] << endl;

return 0;
}

// Sets argument number to 1001 and sets first element of argument numbers[] to 5555
void m(int& number, int numbers[]) // changed int to int& so that argument number is set to 1001
{ 
number = 1001; 
numbers[0] = 5555; 
}