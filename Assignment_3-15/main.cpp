// Program
#include <chrono>
#include <iostream>
using namespace std;
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
int main()
{
    int i, N = 21, M = 420; // i used for loops, N is the size of the linked list, M is how many time we move to next node
    link t = new node(1, 0); // initialize link t with item=1 and next being nothing(0)
    t->next = t;             // t->next points to itself; effectively a circular linked list
    link x = t;              // used to navigate circularly linked list

    auto start = chrono::steady_clock::now(); // start time for circularly linked list
    for(i = 2; i <= N; i++)                   // for loop...
        x = (x->next = new node(i, t));       // creates circularly linked list of size N
    while(x != x->next) { // while x->next does not point to itself (i.e. circular linked list has only x as a node)...
        for(i = 1; i < M; i++) // move to next node M-1 times
            x = x->next;
        x->next = x->next->next; // effectively removes next node from list. (i.e. Mth node from x is removed)
    }
    cout << x->item << endl;                   // output the item in the last node left in the list
    auto finish = chrono::steady_clock::now(); // end time for circularly linked list
    auto runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start); // runtime for circularly linked list
    cout << "Runtime for original circularly linked list (N = " << N << ", M = " << M << "): " << runtime.count()
         << " ns" << endl; // runtime output for original circularly linked list

    // Implementing above code using an array of size N
    int list[N];   // declare array to hold psuedo circularly linked list
    int index = 0; // tells us which index we are on
    int size = N;  // tells us the size of list

    start = chrono::steady_clock::now(); // start time for circularly linked list
    // Fill array with values like the linked list above
    for(i = 1; i <= N; i++)
        list[i] = i;
    while(size != 1) {          // while there is more than 1 element in list...
        for(i = 1; i <= M; i++) // move to next index M times
        {
            if(index != N - 1) // if we are not at the end of the array...
                index++;       // simply increase index by 1
            else
                index = 0; // else reset to beginning of array.
            // if(list[index] == -1)        // if list value at index is -1 (empty)...
            while(list[index] == -1) // while index is -1 (empty)... search for an index that is not empty
            {
                if(index != N - 1) // if we are not at the end of the array...
                    index++;
                else
                    index = 0; // else circle to beginning of array, index 0.
            }
        }
        list[index] = -1; // delete element by changing it to -1
        size--;           // reduce size
    }
    // Find last remaining element in list that is not -1
    for(i = 0; i < N; i++)
        if(list[i] != -1)
            index = i;
    cout << list[index] << endl;
    finish = chrono::steady_clock::now();                                 // end time for array circularly linked list
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start); // runtime for array circularly linked list
    cout << "Runtime for psuedo circularly linked list (N = " << N << ", M = " << M << "): " << runtime.count() << " ns"
         << endl; // runtime output for psuedo circularly linked list
}
