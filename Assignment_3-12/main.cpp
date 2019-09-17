// deque Demo
#include <algorithm> // used for the sort and merge functions
#include <deque>     // used to create and modify deque objects
#include <iostream>  // used for output
//#include <list>
//#include <string>
using namespace std;

// Prints a deque of any data type.
template <class T> void printDeque(const deque<T>& lst, string s)
{
    cout << s << ": ";
    typename deque<T>::const_iterator i = lst.begin(); // creates iterator i at begin() of deque
    for(; i != lst.end(); i++)// while the iterator is not at the end...
        cout << *i << ' '; // output the dereferenced iterator foloowed by a space
    cout << endl; // go to new line when done
}
int main()
{
    deque<int> dq1;         // declares deque of ints dq1
    dq1.push_front(1);      // pushes 1 to front of dq1
    dq1.push_front(2);      // pushes 2 to front of dq1
    dq1.push_back(3);       // pushes 3 to back of dq1
    dq1.push_back(4);       // pushes 4 to back of dq1
    printDeque(dq1, "dq1"); // outputs "dq1: 2 1 3 4 "
    // initializes deque of ints dq2 with "1 3" from dq1. note that end() refers to AFTER the last number of the deque
    deque<int> dq2(dq1.begin() + 1, dq1.end() - 1); // constructor range is [#,#) (inclusive exclusive)
    dq1[1] = 5;                                     // sets index 1 of dq1 to 5 (i.e. dq1's 1 is now 5)
    dq1.erase(dq1.begin());                         // erases beginning of deq1 (i.e. 2 is erased)
    dq1.insert(dq1.end() - 1, 2, 6);                // inserts 2 6s before the end-1 index of dq1 (i.e. before the 4)
    sort(dq1.begin(), dq1.end());                   // sorts dq1 from begin() to end() (the whole deque) ascending
    deque<int> dq3;                                 // declare deque of ints dq3
    dq3.resize(dq1.size() + dq2.size());            // set size of dq3 to that of dq1 + dq2
    // Merges dq1 begin() to end() and dq2 begin() to end() at begin() of dq3. this is NOT concatenation
    merge(dq1.begin(), dq1.end(), dq2.begin(), dq2.end(),
        dq3.begin());       // merges in ascending order. assumes other deques are sorted
    printDeque(dq1, "dq1"); // outputs "dq1: 3 4 5 6 6"
    printDeque(dq2, "dq2"); // outputs "dq2: 1 3"
    printDeque(dq3, "dq3"); // outputs "dq3: 1 3 3 4 5 6 6"
    return 0;
}