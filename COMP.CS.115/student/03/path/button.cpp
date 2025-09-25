#include "button.hh"

Button::Button(char c) : char_(c) {}

Button::~Button() {}

char Button::GetColor() const { return char_; }

bool Button::IsGreen() const { return char_ == 'G'; }

bool Button::IsRed() const { return char_ == 'R'; }

