#include "rectangle.hh"
#include <iostream>


Rectangle::Rectangle(char color, double width, double height) : Shape(color), width_(width), height_(height)
{}

Rectangle::~Rectangle()
{}

double Rectangle::area()
{
    return height_ * width_;
}

double Rectangle::circumference()
{
    return 2 * (height_ + width_);
}

void Rectangle::print(int running_number)
{
    Shape::print(running_number);
    std::cout << COLOR_NAMES.at(get_color()) << " rectangle with width " << width_
              << " and height " << height_ << "\n";
    std::cout << "Area: " << area() << "\n";
    std::cout << "Circumference: " << circumference() << "\n\n";
}
