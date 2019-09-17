////TestThinker.cpp /////////////////////////

#include "thinker.h"

int main()
{
    // Declare two thinking_cap objects: student and fan
    thinking_cap student;
    thinking_cap fan;

    student.slots("Hello", "Goodbye"); // Sets green_string to "Hello" and red_string to "Goodbye"
    fan.slots("Go Cougars!", "Boo!"); // Sets green_string to "Go Cougers!" and red_string to "Boo!"

    student.push_green(); // Display green_string of student
    fan.push_green(); // Display green_string of fan
    student.push_red(); // Display red_string of student

    return 0;
}
