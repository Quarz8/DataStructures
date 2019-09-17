#include <iostream>
using namespace std;

// Returns a pointer to a reversed version of array list of size 6 from index 0 to index size-1
int* reverse(const int* list, int size)
{
    int* result = new int[6]; // Had to change "int result" to "int * result=new int[6]";
    for(int i = 0, j = size - 1; i < size; i++, j--) {
        result[j] = list[i];
    }
    return result;
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