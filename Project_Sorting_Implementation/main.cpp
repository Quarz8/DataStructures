// C++11. This program shows runtimes of insertion, bubble, heap, merge, quick, and std::sort sorting algorithms
#include <algorithm> // std::sort
#include <array>     // array functionality
#include <chrono>    // used to calculate runtimes
#include <iostream>  // input/output
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
// Implementation of sorting algorithms insertion, bubble, heap, merge, quick
// from GeeksforGeeks.com

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int* xp, int* yp) // helper function for bubbleSort and quickSort
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Function to sort an array using bubble sort*/
void bubbleSort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for(j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) // helper function for heapSort
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if(l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if(r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if(largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

/* Function to sort an array using heap sort*/
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for(int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) // helper function for mergeSort
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* Function to sort an array using merge sort*/
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if(l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high) // helper function for quickSort
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for(int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if(arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Function to sort an array using quick sort*/
/* arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if(low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);  // quickSort left partition
        quickSort(arr, pi + 1, high); // quickSort right partition
    }
}
///////////////////////////////////////////////////////////////////////////////////////

// Print int array function, used by me to ensure algorithms work properly, not needed for purposes of demonstration
template <size_t SIZE> void printIntArray(array<int, SIZE>& arr)
{
    for(unsigned int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Testing runtimes of each sorting algorithm
int main()
{
    // Declare int array objects to copy and test (these are the original arrays)
    array<int, 100> sortedArray100;
    array<int, 1000> sortedArray1000;
    array<int, 100> randomArray100;   // random ints 0-99
    array<int, 1000> randomArray1000; // random ints 0-999
    array<int, 100> backwardsArray100;
    array<int, 1000> backwardsArray1000;

    // Populate sorted array size 100 with ints ordered 0-99 (sorted)
    for(int i = 0; i < 100; i++)
        sortedArray100[i] = i;
    // Populate sorted array size 1000 with ints ordered 0-999 (sorted)
    for(int i = 0; i < 1000; i++)
        sortedArray1000[i] = i;
    srand(time(NULL)); // seed for rand()
    // Populate random array size 100 with random ints 0-99
    for(int i = 0; i < 100; i++)
        randomArray100[i] = rand() % 100;
    // Populate random array size 1000 with random ints 0-999
    for(int i = 0; i < 1000; i++)
        randomArray1000[i] = rand() % 1000;
    // Populate backwards array size 100 with ints ordered 99-0
    for(int i = 0, e = 99; i < 100; i++, e--)
        backwardsArray100[i] = e;
    // Populate backwards array size 1000 with ints ordered 999-0
    for(int i = 0, e = 999; i < 1000; i++, e--)
        backwardsArray1000[i] = e;

    // Note: arrays with suffix IS will be used by insertionSort, BS by bubbleSort, etc....
    // Container arrays for holding copies of the above arrays size 100...
    array<int, 100> sortedArray100IS, sortedArray100BS, sortedArray100HS, sortedArray100MS, sortedArray100QS,
        sortedArray100std, randomArray100IS, randomArray100BS, randomArray100HS, randomArray100MS, randomArray100QS,
        randomArray100std, backwardsArray100IS, backwardsArray100BS, backwardsArray100HS, backwardsArray100MS,
        backwardsArray100QS, backwardsArray100std;
    // and array size 1000
    array<int, 1000> sortedArray1000IS, sortedArray1000BS, sortedArray1000HS, sortedArray1000MS, sortedArray1000QS,
        sortedArray1000std, randomArray1000IS, randomArray1000BS, randomArray1000HS, randomArray1000MS,
        randomArray1000QS, randomArray1000std, backwardsArray1000IS, backwardsArray1000BS, backwardsArray1000HS,
        backwardsArray1000MS, backwardsArray1000QS, backwardsArray1000std;

    // Copy original size 100 arrays into respective container arrays
    sortedArray100IS = sortedArray100BS = sortedArray100HS = sortedArray100MS = sortedArray100QS = sortedArray100std =
        sortedArray100;
    randomArray100IS = randomArray100BS = randomArray100HS = randomArray100MS = randomArray100QS = randomArray100std =
        randomArray100;
    backwardsArray100IS = backwardsArray100BS = backwardsArray100HS = backwardsArray100MS = backwardsArray100QS =
        backwardsArray100std = backwardsArray100;
    // Copy original size 1000 arrays into respective container arrays
    sortedArray1000IS = sortedArray1000BS = sortedArray1000HS = sortedArray1000MS = sortedArray1000QS =
        sortedArray1000std = sortedArray1000;
    randomArray1000IS = randomArray1000BS = randomArray1000HS = randomArray1000MS = randomArray1000QS =
        randomArray1000std = randomArray1000;
    backwardsArray1000IS = backwardsArray1000BS = backwardsArray1000HS = backwardsArray1000MS = backwardsArray1000QS =
        backwardsArray1000std = backwardsArray1000;

    /* Note: I have tested the arrays above, they work as intended. */
    /* Testing algorithm runtimes... */

    // Call bubbleSort on unused original array serves as buffer for when 
    // program starts so the timed call does not take longer than it otherwise would.
    // For some reason, insertionSort takes longer to sort a sorted array 
    // of size 100 than it does to sort one of size 1000 without this...
    bubbleSort(sortedArray100.begin(), 100); 

    ///////////////////////////////////////////// SORTED ARRAYS SIZE 100 /////////////////////////////////////////////
    cout << "SORTING SORTED ARRAYS SIZE 100..." << endl;
    auto start = chrono::steady_clock::now();                                  // start time for sorting algorithm
    insertionSort(sortedArray100IS.begin(), 100);                              // insertion sorting array size 100
    auto finish = chrono::steady_clock::now();                                 // end time for sorting algorithm
    auto runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start); // runtime for sorting algorithm
    cout << "Runtime for insertionSort:\t" << runtime.count() << " ns"<< endl; // outputting runtime
                                                                               // vvv Same format for each runtime block vvv
    start = chrono::steady_clock::now();
    bubbleSort(sortedArray100BS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for bubbleSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    heapSort(sortedArray100HS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for heapSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    mergeSort(sortedArray100MS.begin(), 0, 99);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for mergeSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    quickSort(sortedArray100QS.begin(), 0, 99);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for quickSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    sort(sortedArray100std.begin(), sortedArray100std.end());
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for std::sort:\t\t" << runtime.count() << " ns" << endl;

    ///////////////////////////////////////////// SORTED ARRAYS SIZE 1000 /////////////////////////////////////////////
    cout << "SORTING SORTED ARRAYS SIZE 1000..." << endl;
    start = chrono::steady_clock::now();
    insertionSort(sortedArray1000IS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for insertionSort:\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    bubbleSort(sortedArray1000BS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for bubbleSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    heapSort(sortedArray1000HS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for heapSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    mergeSort(sortedArray1000MS.begin(), 0, 999);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for mergeSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    quickSort(sortedArray1000QS.begin(), 0, 999);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for quickSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    sort(sortedArray1000std.begin(), sortedArray1000std.end());
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for std::sort:\t\t" << runtime.count() << " ns" << endl;

    ///////////////////////////////////////////// RANDOM ARRAYS SIZE 100 /////////////////////////////////////////////
    cout << "SORTING RANDOM ARRAYS SIZE 100..." << endl;
    start = chrono::steady_clock::now();
    insertionSort(randomArray100IS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for insertionSort:\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    bubbleSort(randomArray100BS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for bubbleSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    heapSort(randomArray100HS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for heapSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    mergeSort(randomArray100MS.begin(), 0, 99);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for mergeSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    quickSort(randomArray100QS.begin(), 0, 99);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for quickSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    sort(randomArray100std.begin(), randomArray100std.end());
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for std::sort:\t\t" << runtime.count() << " ns" << endl;

    ///////////////////////////////////////////// RANDOM ARRAYS SIZE 1000 /////////////////////////////////////////////
    cout << "SORTING RANDOM ARRAYS SIZE 1000..." << endl;
    start = chrono::steady_clock::now();
    insertionSort(randomArray1000IS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for insertionSort:\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    bubbleSort(randomArray1000BS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for bubbleSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    heapSort(randomArray1000HS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for heapSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    mergeSort(randomArray1000MS.begin(), 0, 999);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for mergeSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    quickSort(randomArray1000QS.begin(), 0, 999);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for quickSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    sort(randomArray1000std.begin(), randomArray1000std.end());
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for std::sort:\t\t" << runtime.count() << " ns" << endl;

    //////////////////////////////////////////// BACKWARDS ARRAYS SIZE 100 ///////////////////////////////////////////////
    cout << "SORTING BACKWARDS ARRAYS SIZE 100..." << endl;
    start = chrono::steady_clock::now();
    insertionSort(backwardsArray100IS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for insertionSort:\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    bubbleSort(backwardsArray100BS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for bubbleSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    heapSort(backwardsArray100HS.begin(), 100);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for heapSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    mergeSort(backwardsArray100MS.begin(), 0, 99);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for mergeSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    quickSort(backwardsArray100QS.begin(), 0, 99);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for quickSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    sort(backwardsArray100std.begin(), backwardsArray100std.end());
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for std::sort:\t\t" << runtime.count() << " ns" << endl;

    //////////////////////////////////////////// BACKWARDS ARRAYS SIZE 1000 ///////////////////////////////////////////////
    cout << "SORTING BACKWARDS ARRAYS SIZE 1000..." << endl;
    start = chrono::steady_clock::now();
    insertionSort(backwardsArray1000IS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for insertionSort:\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    bubbleSort(backwardsArray1000BS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for bubbleSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    heapSort(backwardsArray1000HS.begin(), 1000);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for heapSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    mergeSort(backwardsArray1000MS.begin(), 0, 999);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for mergeSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    quickSort(backwardsArray1000QS.begin(), 0, 999);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for quickSort:\t\t" << runtime.count() << " ns" << endl;

    start = chrono::steady_clock::now();
    sort(backwardsArray1000std.begin(), backwardsArray1000std.end());
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "Runtime for std::sort:\t\t" << runtime.count() << " ns" << endl;

    /* All copied arrays are now sorted. */

    // printIntArray(backwardsArray1000MS); // testing array values
    // printIntArray(backwardsArray1000);   // to ensure code works as intended
    return 0;
}
