#include "circle.hh"
#include <iostream>


Circle::Circle(char color, double radius) : Shape(color), radius_(radius)
{}

Circle::~Circle()
{}

double Circle::area()
{
    return PI * radius_ * radius_;
}

double Circle::circumference()
{
    return 2 * PI * radius_;
}

void Circle::print(int running_number)
{
    Shape::print(running_number);
    std::cout << COLOR_NAMES.at(get_color()) << " circle with radius " << radius_ << "\n";
    std::cout << "Area: " << area() << "\n";
    std::cout << "Circumference: " << circumference() << "\n\n";
}

