///////////////// Program 2.1

#include <iostream>
using namespace std;

const int SIZE = 4; // Added assignment operator (=)

void printArray(int list[], int arraySize); // implementation/documentation on line 40

// Copies the elements list[] to newList[] in reverse order.
// int size is the size of newList[] (how many elements are copied)
void reverse(const int list[], int newList[], int size)
{
    for(int i = 0, j = size - 1; i < size; i++, j--) {
        newList[j] = list[i];
    }
}

// Sets first element of selected int array to 100
void p(int list[], int arraySize) // Removed const to allow assignment of values to list[].
{
    // The arraySize parameter is just there to look pretty. Pretty UGLY. Ha. Goteem.
    list[0] = 100;
}

// Tests all functions
int main()
{
    // SIZE = 4; // Size is already a constant set to 4.
    int newList[SIZE];
    int numbers[] = { 1, 4, 3, 6, 8 };
    p(numbers, 5);
    printArray(numbers, 5);
    reverse(numbers, newList, SIZE); // Changed list to numbers
    printArray(newList, SIZE);

    return 0;
}

// Displays each value in an array up to index arraySize-1, each separated by a space.
// If you want to display the entire array, arraySize should be equal to the size of list[]
void printArray(int list[], int arraySize)
{
    for(int i = 0; i < arraySize; i++) {
        cout << list[i] << " ";
    }
}