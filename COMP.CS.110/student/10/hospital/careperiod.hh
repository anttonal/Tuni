/* Class Care_Period
 * ----------
 * COMP.CS.110 SPRING 2024
 * ----------
 * Class for describing a patient's care period in hospital.
 *
 * Note: Students need to implement almost all of this class by themselves.
 * */
#ifndef Care_Period_HH
#define Care_Period_HH

#include "person.hh"
#include "date.hh"
#include <string>
#include <set>

class Care_Period
{
public:
    /**
      * @brief Care_Period
      * @param start date given as a string (ddmmyyyy)
      * @param patient whose care period will be created
      */
    Care_Period(const std::string& start, Person* patient);

    /**
      * @brief Care_Period
      * @param start date given as a Date object
      * @param patient whose care period will be created
      */
    Care_Period(const Date& start, Person* patient);

    /**
      * @brief destructor
      */
    ~Care_Period();

    /**
      * @brief print_patient_info
      * prints all the patient's info in the right format
      */
    void print_patient_info() const;

    /**
      * @brief print_staff_info
      * prints all the staff member's info in the right format
      */
    void print_staff_info() const;

    /**
      * @brief assign_staff
      * @param staff_member
      * assigns a staff member into a patient's care period
      */
    void assign_staff(Person* staff_member);

    /**
      * @brief end
      * @param today
      * sets the end_ attribute to the current day
      */
    void end(Date today);

private:

    // Set of staff member names assigned to the care period
    std::set<std::string> staff_;

    // The care period's patient
    Person* patient_;

    // The starting date of the care period
    Date start_;

    // The ending date of the care period
    Date end_;
};

#endif // Care_Period_HH
