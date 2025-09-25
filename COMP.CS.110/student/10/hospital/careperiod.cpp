#include "careperiod.hh"
#include <iostream>

Care_Period::Care_Period(const std::string& start, Person* patient):
    patient_(patient), start_(Date(start))
{
}

Care_Period::Care_Period(const Date &start, Person* patient):
    patient_(patient), start_(start)
{
}

Care_Period::~Care_Period()
{
}

void Care_Period::print_patient_info() const
{
    std::cout << "* Care period: ";
    start_.print();
    if( end_.is_default() )
    {
        std::cout << " -";
    }
    else
    {
        std::cout << " - ";
        end_.print();
    }
    std::cout << std::endl;
    std::cout << "  - Staff:";
    if( staff_.empty() )
    {
        std::cout << " None";
    }
    else
    {
        for( const std::string& staff_member : staff_ )
        {
            std::cout << " " << staff_member;
        }
    }
    std::cout << std::endl;
}

void Care_Period::print_staff_info() const
{
    start_.print();
    if( end_.is_default() )
    {
        std::cout << " -";
    }
    else
    {
        std::cout << " - ";
        end_.print();
    }
    std::cout << std::endl << "* Patient: " << patient_->get_id() << std::endl;
}

void Care_Period::assign_staff(Person* staff_member)
{
    staff_.insert(staff_member->get_id());
    std::cout << "Staff assigned for: " << patient_->get_id() << std::endl;
}

void Care_Period::end(Date today)
{
    end_ = today;
}
