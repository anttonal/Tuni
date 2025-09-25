#include "teacher.hh"
#include <algorithm>

Teacher::Teacher(const std::string &name, int age, const std::string office_num)
    : Person(name, age), office_num_(office_num)
{
    std::cout << "Teacher created: " << name << std::endl;
}

Teacher::~Teacher()
{
    std::cout << "Teacher destructed: " << this->get_name() << std::endl;
}

void Teacher::change_room(const std::string &new_room)
{
    office_num_ = new_room;
}

void Teacher::add_new_course(const std::string &course)
{
    course_resp_.push_back(course);
}

void Teacher::remove_course(const std::string &course)
{
    auto it = std::find(course_resp_.begin(), course_resp_.end(), course);
    if (it != course_resp_.end()) {
        course_resp_.erase(it);
    }
}


void Teacher::print(std::ostream &output) const
{
    Person::print(output);
    output << "*** " << office_num_ << ": ";

    if (course_resp_.empty()){
        output << "No responsibilities" << std::endl;
    }
    else {
        std::vector<std::string> sorted_courses = course_resp_;
        std::sort(sorted_courses.begin(), sorted_courses.end());

        for (const std::string &course : sorted_courses)
        {
            if (course == sorted_courses.back()){
                output << course << std::endl;
            }
            else {
                output << course << ", ";
            }
        }
    }
}
