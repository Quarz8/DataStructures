//////// thinker.cpp /////////////////////////////

#include <iostream> // Changed outdated iostream.h

#include <cstring> // Changed stdlib.h to cstring to sllow use of strlen and strcpy

#include <cassert> // Added to allow use of assert

#include "thinker.h"

using namespace std; // Added to alllow use of cout and endl

void thinking_cap::slots(char new_green[], char new_red[])
{
    // Asserts both char[] are less than strlen 50
    assert(strlen(new_green) < 50);
    assert(strlen(new_red) < 50);

    // Copies each new char[] to their respective string
    strcpy(green_string, new_green);
    strcpy(red_string, new_red);
}

void thinking_cap::push_green() const // added parentheses and const to complete function declaration
{
    cout << green_string << endl; // outputs green_string then goes to new line
}

void thinking_cap::push_red() const // added parentheses and const to complete function declaration
{
    cout << red_string << endl; // outputs red_string then goes to new line
}
