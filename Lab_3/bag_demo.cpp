// FILE: bag_demo.cxx
// This is a small demonstration program showing how the bag class is used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "bag1.h"      // With value_type defined as an int
using namespace std;
using namespace main_savitch_3;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bag, stopping
// when the bag is full or when the user types a negative number.

void check_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bag when it is typed,
// stopping when the bag is empty.

// User is prompted to input ages of family, which are each placed into the bag ages.
// The user is then prompted to re-enter these ages, which are then removed from the bag
// one at a time. Once all ages have been removed, the message "May your family live long and prosper."
// is displayed and the program exits successfully.
int main( )
{
    bag ages;
    
    get_ages(ages);
    check_ages(ages);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;  
}


void get_ages(bag& ages)
{
    int user_input; // Variable to hold user input

    cout << "Type the ages in your family." << endl; // Prompt user to enter ages and a negative number when done.
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input; // Take user input
    while (user_input >= 0) // While user hasn't input terminating negative number...
    {
        // Checks validity of user_input
        if (cin.fail()) {
            cout << "Invalid Input (Input must be an integer)" << endl;
            cin.clear(); // clear cin error flag
            cin.ignore(10000, '\n'); // ignore problem input (clears input stream up to 10,000 char until '\n' is reached. This '\n' is where the last input was 'entered')
        }
        else if (ages.size( ) < ages.CAPACITY) 
            ages.insert(user_input);
        else 
            cout << "I have run out of room and can't add that age." << endl;
        cin >> user_input; // Takes user input again
    }
}

void check_ages(bag& ages)
{
    int user_input; // Variable to hold user input

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        
        // Checks validity of user_input
        if(cin.fail()) {
            cout << "Invalid Input (Input must be an integer)" << endl;
            cin.clear(); // clear cin error flag
            cin.ignore(10000, '\n'); // ignore problem input (clear input stream up to 10,000 char until '\n' is reached. This '\n' is where the last input was 'entered')
        }
        else if (ages.erase_one(user_input)) // If user_input is erased from ages...
            cout << "Yes, I've got that age and will remove it." << endl;
        else
            cout << "No, that age does not occur!" << endl;   
    }
}