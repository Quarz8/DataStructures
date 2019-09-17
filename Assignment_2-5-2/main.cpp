#include <iostream>
using namespace std;

// Returns a pointer to a reversed version of array list from index 0 to index size-1
int* reverse(const int* list, int size)
{
    int* result = new int[size]; // creates int pointer to an array of values
    for(int i = 0, j = size - 1; i < size; i++, j--) {
        result[j] = list[i]; // assigns values from list to result in reverse order up to index size-1
    }
    return result; // returns pointer result
}

// Prints array list from index 0 to index size-1
void printArray(const int* list, int size)
{
    for(int i = 0; i < size; i++)
        cout << list[i] << " ";
}

// Tests printArray and reverse functions
int main()
{
    int list[] = { 1, 2, 3, 4, 5, 6 }; // initialize array list with values 1-6
    printArray(list, 6);               // Use printArray to print list
    cout << endl;                      // go to next line
    int* p = reverse(list, 6);         // create pointer to reversed version of list array
    printArray(p, 6);                  // Print the values in the array (reverse of list)
    cout << endl;                      // go to next line
    return 0;
}