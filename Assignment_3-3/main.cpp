#include <chrono>
#include <iostream>
using namespace std;

// Each 3.2 code fragments each made/remade into a function named after its repective letter. Slight changes made to
// allow code to compile and run.

void fragmentA(int n)
{
    int sum = 0; // declared sum as an int
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n * n; j++)
            sum++;
}

long fragmentB(long index)
{
    if(index == 0) // Base case
        return 0;
    else if(index == 1) // Base case
        return 1;
    else // Reduction and recursive calls
        return fragmentB(index - 1) +
            fragmentB(index - 2); // '‐' ("en dash" character) in original fragment changed to '-'
}

int fragmentC(int m, int n)
{
    if(m % n == 0)
        return n;
    else
        return fragmentC(n, m % n);
}

void fragmentD(int n)
{
    int sum = 0; // declared sum as an int
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i * i; j++)
            for(int k = 0; k < j; k++) // declared k as an int
                sum++;
}

void fragmentE(int n)
{
    int sum = 0; // declared sum as an int
    for(int i = 1; i < n; i++)
        for(int j = 1; j < i * i; j++)
            if(j % i == 0)
                for(int k = 0; k < j; k++) // declared k as an int
                    sum++;
}

int main()
{

    cout << "Running each code fragment with different N values:" << endl;

    // It should be noted that fragmentC() is a special case, as the runtime depends on the number of digits in the
    // smallest number instead of a simple N value. Worst case runtime occurs when m and n are two consecutive fibonacci
    // numbers, so that is what is used.
    int N = 10; // N represents the input size
    cout << "Running with N = 10..." << endl;
    auto start = chrono::steady_clock::now();
    fragmentA(N);
    auto finish = chrono ::steady_clock::now();
    auto runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentA() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentB(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentB() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentC(5, 8);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentC() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentD(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentD() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentE(N);
    finish = chrono::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentE() runtime: " << runtime.count() << " ns" << endl;

    N = 20; // N represents the input size
    cout << "Running with N = 20..." << endl;
    start = chrono::steady_clock::now();
    fragmentA(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentA() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentB(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentB() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentC(34, 55);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentC() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentD(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentD() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentE(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentE() runtime: " << runtime.count() << " ns" << endl;

    N = 40; // N represents the input size
    cout << "Running with N = 40..." << endl;
    start = chrono::steady_clock::now();
    fragmentA(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentA() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentB(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentB() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentC(233, 377);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentC() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentD(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentD() runtime: " << runtime.count() << " ns" << endl;
    start = chrono::steady_clock::now();
    fragmentE(N);
    finish = chrono ::steady_clock::now();
    runtime = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "fragmentE() runtime: " << runtime.count() << " ns" << endl;

    return 0;
}
