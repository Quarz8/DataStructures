///////// thinker.h ///////////////////

// Implicit CONSTRUCTOR for the thinking_cap class:
//   thinking_cap();
//     Postcondition: The object has been initialized, and is ready to accept
//     char arrays with strlen < 50 through the slots(char new_green[], char new_red[])
//     function. Each char array can be displayed using the push_green() or push_red()
//     functions, respectively.
//
// PUBLIC member functions for the thinking_cap class:
//   void slots(char new_green[], char new_red[])
//     Precondition: Both strlen of new_green[] and new_red[] are less than 50.
//     Postcondition: green_string and red_string set to new_green[] and new_red[]
//     respectively.
//   void push_green() const
//     Postcondition: Displays value held in green_string
//   void push_red() const
//     Postcondition: Displays value held in red_string

class thinking_cap
{
public:
    void slots(char new_green[], char new_red[]);
    void push_green() const;
    void push_red() const;
private:
    char green_string[50];
    char red_string[50];
};