#include "programmer.hh"

Programmer::Programmer(int from_year) : Role(from_year), skills_{}
{}

Programmer::~Programmer()
{}

void Programmer::add_skill(const std::string &skill)
{
    skills_.insert(skill);
}

void Programmer::print(std::ostream &output) const
{
    if (skills_.empty()) {
        output << "No skills" << std::endl;
    }
    else {
        output << "Skills:";
        for (const std::string &skill : skills_) {
            output << " " << skill;
        }
        output << std::endl;
    }
}
