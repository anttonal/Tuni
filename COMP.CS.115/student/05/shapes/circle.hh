#ifndef CIRCLE_HH
#define CIRCLE_HH
#include "shape.hh"

class Circle : public Shape
{
public:
    Circle(char color, double radius);
    virtual ~Circle();
    virtual double area() override;
    virtual double circumference() override;
    virtual void print(int running_number) override;
private:
    double radius_;
};

#endif // CIRCLE_HH
