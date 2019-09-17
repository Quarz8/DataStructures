#include <chrono>   // used for comparing runtimes
#include <iostream> // removed ".h" from iostream
class node
{
public:
    int item;
    node* next;
    node(int x, node* t)
    {
        item = x;
        next = t;
    }
};

typedef node* link;

static const int N = 1000;
int main()
{
    int i, a[N]; // declaring int i for use in loops and array for determining prime numbers

    auto start = std::chrono::steady_clock::now(); // Start time for original code
    // Fills each value with index >=2 in array with 1
    for(i = 2; i < N; i++)                 // for each value in array index 2 through 999...
        a[i] = 1;                          // set value at i to 1
    for(i = 2; i < N; i++)                 // for each value in array index 2 through 999...
        if(a[i])                           // if a[i] is not 0...
            for(int j = i; j * i < N; j++) // for that index i, and its multiples<N...
                a[i * j] = 0;              // replace that multiple's index with 0
    for(i = 2; i < N; i++)                 // for value in the array index 2 through 999...
        if(a[i])                           // if a[i] is not 0...
            std::cout << " " << i;         // output index i (not the value at the index, the index number itself)
    std::cout << std::endl;                // added "std::" to cout and endl
    auto finish = std::chrono::steady_clock::now();                                      // End time for original code
    auto runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start); // Runtime for original code
    // Output runtime for original code
    std::cout << "Runtime for original code: " << runtime.count() << " ns" << std::endl;

    // Using linked lists...
    link head = new node(2, 0); // designated head node with item value of 2. points to nothing(0) for now.
    link x = head;              // iterator initialized as head
    start = std::chrono::steady_clock::now();    // Start time for original code
    for(i = 3; i < N; i++, x = x->next)          // for i==3 through 999...
        x->next = new node(i, 0);                // add another node to end of linked list with item value i
    for(i = 2, x = head; i < N; i++)             // for each node in linked list
        for(int j = 2; j * i < N; j++, x = head) // while j*i<N
            // find occurance of j*i
            for(int k = 2; k < N; k++, x = x->next) // for each node in list
                if(x->item == j * i)
                    x->item = 0; // remove said occurence from linked list
    // Prints primes
    for(i = 2, x = head; i < N; i++, x = x->next)
        if(x->item)
            std::cout << " " << i;
    std::cout << std::endl;
    finish = std::chrono::steady_clock::now();                                      // End time for original code
    runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start); // Runtime for original code
    // Output runtime for linked list code
    std::cout << "Runtime for linked list code: " << runtime.count() << " ns" << std::endl;
}