#ifndef ELEPHANT_HH
#define ELEPHANT_HH
#include "mammal.hh"

class Elephant : public Mammal
{
public:
    Elephant();
    virtual ~Elephant();
    void vocalize(std::ostream& output) const override;
};

#endif // ELEPHANT_HH
