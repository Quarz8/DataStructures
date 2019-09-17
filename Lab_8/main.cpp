#include <iostream>
using namespace std;

/* Class declaration for Stack */
template <typename T> class Stack
{
public:
    Stack();             // constructor; sets size to 0
    bool empty() const;  // returns true iff size is 0
    T top() const;       // returns element at top of stack
    void push(T value);  // inserts value into elements at index size, then increments size by 1
    void pop();          // decrements size by 1 (i.e. element at top of stack is effectively removed)
    int getSize() const; // returns current size

private:
    T elements[100]; // array of 100 elements of type T
    int size;        // current size of the stack
};

/* Test program for the Stack class */
int main()
{
    double a = 3.141592653589793, b = 6.9, c = 8.21; // double values used in doubleStack

    // Declare 2 stacks of doubles and ints respectively
    cout << "Declared 2 stacks: doubleStack and intStack" << endl;
    Stack<double> doubleStack; // stack of double values
    Stack<int> intStack;       // stack of int values

    // Testing doubleStack
    cout << "\nTesting doubleStack..." << endl;
    // Attempt to pop empty stack
    doubleStack.pop();
    // Push doubles a-c to doubleStack
    doubleStack.push(a);
    doubleStack.push(b);
    doubleStack.push(c);
    // Display top of doubleStack (c)
    cout << doubleStack.top() << endl;
    // Pop doubleStack, then display top (b)
    doubleStack.pop(); // pops c
    cout << doubleStack.top() << endl;
    // Pop doubleStack again, and call empty()
    doubleStack.pop(); // pops b
    cout << doubleStack.empty() << endl;
    // Pop doubleStack one more time, and call empty() again
    doubleStack.pop(); // pops a
    cout << doubleStack.empty() << endl;

    // Testing intStack
    cout << "\nTesting intStack..." << endl;
    // use for loop to push i to intStack until it is full
    for(int i = 0; i < 100; i++)
        intStack.push(i);
    // Use getSize() to see if intStack is full (i.e. 100)
    cout << intStack.getSize() << endl;
    // Attempt to push another int to the full intStack
    intStack.push(8);

    cout << intStack.getSize() << endl;
    return 0;
}

/* Implementations of Stack class funtions           */
/* Functions changed to display when they are called */
template <typename T> Stack<T>::Stack() // Constructor implementation
{
    cout << "Declared a new stack." << endl;
    size = 0; // sets size to 0
}

template <typename T> bool Stack<T>::empty() const // empty() implementation
{
    cout << "Empty? (1: true | 0: false)" << endl;
    return (size == 0); // returns true iff size is 0 (i.e. stack is empty)
}

template <typename T> T Stack<T>::top() const // top() implementation
{
    cout << "Top: ";
    return elements[size - 1]; // returns top element value of stack
}

// I made a slight change* to the original function, as calling push() when size is 100 or greater
// would previously lead to undefined behaviour as values are assigned out of bounds of the array.
// *Added if else statement to check size does not go over 100.
template <typename T> void Stack<T>::push(T value) // push() implementation
{
    cout << "Pushing " << value << "..." << endl;
    if(size < 100)                // if size is less than 100...
        elements[size++] = value; // sets element[size] to value. increments size
    else
        cout << "Error: Stack is already full. Value not pushed." << endl; // error message displayed
}

// Another slight change* to the original function, as calling pop() on an empty stack
// would previously cause errors in other functions such as empty() and getSize().
// *Added if else statement to check size does not go below 0.
template <typename T> void Stack<T>::pop() // pop() implementation
{
    cout << "Popping..." << endl;
    if(size > 0) // Added another check for size. if size is greater than 0...
        --size;  // decrement size by 1
    else
        cout << "Error: Stack is already empty. Value not popped." << endl; // error message displayed
}

template <typename T> int Stack<T>::getSize() const // getSize() implementation
{
    cout << "Size: ";
    return size;
}
