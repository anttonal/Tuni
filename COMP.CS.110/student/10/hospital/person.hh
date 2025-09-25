/* Class Person
 * ----------
 * COMP.CS.110 SPRING 2024
 * ----------
 * Class for describing a person that can be a patient or a staff member
 * in hospital.
 *
 * Note: Students can change this class, but most probably they need not.
 * */
#ifndef PERSON_HH
#define PERSON_HH

#include "date.hh"
#include <string>
#include <map>
#include <vector>
#include <set>

class Person
{
public:
    /**
     * @brief Person
     * Gives no values for the attributes
     */
    Person();

    /**
     * @brief Person
     * @param id
     * Initializes the attribute id_
     */
    Person(const std::string& id);

    /**
      * @brief destructor
      */
    ~Person();

    /**
     * @brief get_id
     * @return the value of id_
     */
    std::string get_id() const;

    /**
     * @brief get_medicines
     * @return medicines
     */
    std::vector<std::string> get_medicines() const;

    /**
     * @brief add_medicine
     * @param name
     * @param strength
     * @param dosage
     */
    void add_medicine(const std::string& name,
                      unsigned int strength,
                      unsigned int dosage);

    /**
     * @brief remove_medicine
     * @param name
     * Removes the given medicine from the person.
     */
    void remove_medicine(const std::string& name);

    /**
     * @brief print_id
     */
    void print_id() const;

    /**
     * @brief print_medicines
     * @param pre_text is printed before the medicines
     */
    void print_medicines(const std::string& pre_text) const;

    /**
     * @brief operator <
     * @param rhs
     * @return The person object that comes first
     * Comparison operator, enables forming a set of Person objects.
     */
    bool operator<(const Person& rhs) const;

private:

    // Can be a name or any other identifier
    std::string id_;

    /**
      * @brief Perscription
      * @param strength_ The strength of the medication
      * @param dosage_   The dosage of the medication
      */
    struct Prescription
    {
        unsigned int strength_;
        unsigned int dosage_;
    };

    // Medicine names and their prescriptions
    std::map<std::string, Prescription> medicines_;
};

#endif // PERSON_HH
