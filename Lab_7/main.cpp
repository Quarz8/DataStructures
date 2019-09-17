#include <iostream>
using namespace std;

// Outputs "Double" and returns largest generic value
double maxValue(const double& value1, const double& value2)

{
    cout << "Double" << endl;
    if(value1 > value2)
        return value1;
    else
        return value2;
}

// Outputs "Int" and returns largest generic value
int maxValue(const int& value1, const int& value2)

{
    cout << "Int" << endl;
    if(value1 > value2)
        return value1;
    else
        return value2;
}

// Outputs "Template" and returns largest generic value
template <typename T> T maxValue(const T& value1, const T& value2)
{
    cout << "Template" << endl;
    if(value1 > value2)

        return value1;
    else
        return value2;
}

// Test maxValue functions with various inputs/data types
int main()
{
    // Variables for function arguments
    int iX = 8, iY = 21;
    double dX = 6.9, dY = 7.01;
    short sX = 4, sY = 7;
    char cX = 'h', cY = 'k';

    // Testing int arguments
    cout << "Comparing int values: " << iX << " and " << iY << endl;
    cout << maxValue(iX, iY) << endl;
    cout << maxValue<>(iX, iY) << endl;

    // Testing double arguments
    cout << "Comparing double values: " << dX << " and " << dY << endl;
    cout << maxValue(dX, dY) << endl;
    cout << maxValue<>(dX, dY) << endl;

    // Testing short arguments
    cout << "Comparing short values: " << sX << " and " << sY << endl;
    cout << maxValue(sX, sY) << endl;
    cout << maxValue<>(sX, sY) << endl;

    // Testing char arguments
    cout << "Comparing char values: " << cX << " and " << cY << endl;
    cout << maxValue(cX, cY) << endl;
    cout << maxValue<>(cX, cY) << endl;

    return 0;
}