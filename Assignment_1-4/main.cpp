#include <iostream>
using namespace std;

int main()
{
    // Precondition: Each input must be a number
    // Postcondition: Outputs the Celsius to Fahrenheit conversion and Fahrenheit to Celsius conversion
    double nCelsius, nFahr;

    cout << "Enter the temperature in Celsius: ";
    cin >> nCelsius;

    cout << "Celsius " << nCelsius << " is Fahrenheit degree ";
    cout << (double)9 / 5 * nCelsius + 32 << endl; // We can use type casting to avoid truncation when dividing

    cout << "\nEnter the temperature in Fahrenheit: ";
    cin >> nFahr;

    cout << "Fahrenheit " << nFahr << " is Celsius degree ";
    cout << 5.0 / 9 * (nFahr - 32) // We can also just change one or both of the ints in the fraction to a double
         << endl;
    return 0;
}
