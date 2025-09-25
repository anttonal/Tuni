/*
 * File: button.hh
 * Description: Declares the Button class used to represent red and
 *              green buttons on the gameboard. Includes basic functionality
 *              for identifying color.
 */

#ifndef BUTTON_HH
#define BUTTON_HH

class Button
{
public:
    // Constructor (sets the button's color)
    Button(char c);

    // Destructor.
    virtual ~Button();

    // Returns the button's color as a char.
    char GetColor() const;

    // Returns true if the button is green ('G').
    bool IsGreen() const;

    // Returns true if the button is red ('R').
    bool IsRed() const;

private:

    // Stores the button's color.
    const char char_;
};



#endif // BUTTON_HH
