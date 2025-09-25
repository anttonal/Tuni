#include "student.hh"


Student::Student(const std::string &name, int age, const std::string student_num)
    : Person(name, age), student_num_(student_num)
{
    std::cout << "Student created: " << name << std::endl;
}

Student::~Student()
{
    std::cout << "Student destructed: " << this->get_name() << std::endl;
}

void Student::complete_course(const std::string &course)
{
    courses_passed_.push_back(course);
}

void Student::print(std::ostream &output) const
{
    Person::print(output);
    output << "+++ " << student_num_ << ": ";

    if (courses_passed_.empty()){
        output << "No courses completed" << std::endl;
    }
    else {
        for (const std::string &course : courses_passed_)
        {
            if (course == courses_passed_.back()){
                output << course << std::endl;
            }
            else {
                output << course << ", ";
            }
        }
    }
}
