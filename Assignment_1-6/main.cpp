#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    // Postcondition: For an equilateral triangle, square, regular pentagon, hexagon, heptagon,
    // and octagon, displays the areas of each with a side length of 1, 2, 3, 4, 5, and 6.

    // enum for switch statement readability (choosing appropriate area formula)
    enum GeoFigs { TRIANGLE, SQUARE, PENTAGON, HEXAGON, HEPTAGON, OCTAGON };

    // pi constant for use in heptagon area calculation
    const long double PI = 4 * atan(1);

    for(int geoFig = 0; geoFig < 6; geoFig++) {      // For each geoFig in GeoFigs...
        for(int length = 1; length <= 6; length++) { // For lengths 1 through 6...
            // Outputs appropriate geometric figure's lengths and respective areas.
            switch(
                geoFig) { // Format: "The area of ... with side length" << int length << " is " << (area calculation);
            case TRIANGLE:
                cout << "The area of an equilateral triangle with side length " << length << " is "
                     << (sqrt(3) / 4) * pow(length, 2);
                break;
            case SQUARE:
                cout << "The area of a square with side length " << length << " is " << pow(length, 2);
                break;
            case PENTAGON:
                cout << "The area of a regular pentagon with side length " << length << " is "
                     << .25 * (sqrt(5 * (5 + 2 * sqrt(5))) * pow(length, 2));
                break;
            case HEXAGON:
                cout << "The area of a regular hexagon with side length " << length << " is "
                     << ((3 * sqrt(3)) / 2) * pow(length, 2);
                break;
            case HEPTAGON:
                cout << "The area of a regular heptagon with side length " << length << " is "
                     << (7.0 / 4) * pow(length, 2) * (cos(PI / 7) / sin(PI / 7));
                break;
            case OCTAGON:
                cout << "The area of a regular octagon with side length " << length << " is "
                     << 2 * (1 + sqrt(2)) * pow(length, 2);
                break;
            }
            cout << endl; // New line after each area displayed
        }
        cout << endl; // Blank line separating/grouping geoFigs
    }
    return 0;
}
