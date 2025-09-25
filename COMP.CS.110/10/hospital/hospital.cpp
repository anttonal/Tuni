#include "hospital.hh"
#include "utils.hh"
#include <iostream>
#include <set>

Hospital::Hospital()
{
}

Hospital::~Hospital()
{

    // Clearing pointers
    current_patients_.clear();
    staff_care_periods_.clear();
    assigned_medicine_.clear();

    // Deallocating staff
    for( auto& staff_member : staff_ )
    {
        delete staff_member.second;
        staff_member.second = nullptr;
    }

    // Deallocating patient care periods
    for( auto& pair : patient_care_periods_ )
    {
        for( Care_Period* ptr : pair.second )
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    // Deallocating all patients
    for( auto& patient : all_patients_ )
    {
        delete patient.second;
        patient.second = nullptr;
    }
}

void Hospital::set_date(Params params)
{
    std::string day = params.at(0);
    std::string month = params.at(1);
    std::string year = params.at(2);
    if( not utils::is_numeric(day, false) or
        not utils::is_numeric(month, false) or
        not utils::is_numeric(year, false) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    utils::today.set(stoi(day), stoi(month), stoi(year));
    std::cout << "Date has been set to ";
    utils::today.print();
    std::cout << std::endl;
}

void Hospital::advance_date(Params params)
{
    std::string amount = params.at(0);
    if( not utils::is_numeric(amount, true) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    utils::today.advance(stoi(amount));
    std::cout << "New date is ";
    utils::today.print();
    std::cout << std::endl;
}

void Hospital::recruit(Params params)
{
    std::string staff_member_id = params.at(0);
    if( staff_.find(staff_member_id) != staff_.end() )
    {
        std::cout << ALREADY_EXISTS << staff_member_id << std::endl;
        return;
    }

    Person* new_staff_member = new Person(staff_member_id);
    staff_.insert({staff_member_id, new_staff_member});
    staff_care_periods_[staff_member_id];

    std::cout << STAFF_RECRUITED << std::endl;
}

void Hospital::print_all_staff(Params)
{
    if( staff_.empty() )
    {
        std::cout << "None" << std::endl;
        return;
    }
    for( std::map<std::string, Person*>::const_iterator iter = staff_.begin();
         iter != staff_.end();
         ++iter )
    {
        std::cout << iter->first << std::endl;
    }
}

void Hospital::add_medicine(Params params)
{
    std::string medicine = params.at(0);
    std::string strength = params.at(1);
    std::string dosage = params.at(2);
    std::string patient = params.at(3);
    if( not utils::is_numeric(strength, true) or
        not utils::is_numeric(dosage, true) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    std::map<std::string, Person*>::const_iterator
            patient_iter = current_patients_.find(patient);
    if( patient_iter == current_patients_.end() )
    {
        std::cout << CANT_FIND << patient << std::endl;
        return;
    }
    patient_iter->second->add_medicine(medicine, stoi(strength), stoi(dosage));
    assigned_medicine_[medicine].insert(current_patients_[patient]);

    std::cout << MEDICINE_ADDED << patient << std::endl;
}

void Hospital::remove_medicine(Params params)
{
    std::string medicine = params.at(0);
    std::string patient = params.at(1);
    std::map<std::string, Person*>::const_iterator
            patient_iter = current_patients_.find(patient);
    if( patient_iter == current_patients_.end() )
    {
        std::cout << CANT_FIND << patient << std::endl;
        return;
    }
    patient_iter->second->remove_medicine(medicine);
    assigned_medicine_[medicine].erase(current_patients_[patient]);

    if( assigned_medicine_[medicine].empty() )
    {
        assigned_medicine_.erase(medicine);
    }

    std::cout << MEDICINE_REMOVED << patient << std::endl;
}

void Hospital::enter(Params params)
{
    std::string patient_id = params[0];
    if( current_patients_.find(patient_id) != current_patients_.end() )
    {
        std::cout << ALREADY_EXISTS << patient_id << std::endl;
        return;
    }

    Person* patient = nullptr;

    if( all_patients_.find(patient_id) != all_patients_.end())
    {
        patient = all_patients_[patient_id];
    }
    else
    {
        patient = new Person(patient_id);
    }

    current_patients_[patient_id] = patient;
    all_patients_[patient_id] = patient;

    Care_Period* new_care_period = new Care_Period(utils::today, patient);
    patient_care_periods_[patient_id].insert(new_care_period);

    std::cout << PATIENT_ENTERED << std::endl;
}

void Hospital::leave(Params params)
{
    std::string patient_id = params[0];
    if( current_patients_.find(patient_id) != current_patients_.end() )
    {
        Care_Period* current_care_period = *(patient_care_periods_[patient_id].rbegin());
        current_care_period->end(utils::today);

        current_patients_.erase(patient_id);

        std::cout << PATIENT_LEFT << std::endl;
    }
    else
    {
        std::cout << CANT_FIND << patient_id << std::endl;
    }
}

void Hospital::assign_staff(Params params)
{
    std::string staff_member_id = params[0];
    std::string patient_id = params[1];

    if( staff_.find(staff_member_id) != staff_.end() )
    {
        if( current_patients_.find(patient_id) != current_patients_.end() )
        {
            Care_Period* current_care_period = *(patient_care_periods_[patient_id].rbegin());
            current_care_period->assign_staff(staff_[staff_member_id]);

            staff_care_periods_[staff_member_id].insert(current_care_period);
        }
        else
        {
            std::cout << CANT_FIND << patient_id << std::endl;
        }
    }
    else
    {
        std::cout << CANT_FIND << staff_member_id << std::endl;
    }
}

void Hospital::print_patient_info(Params params)
{
    std::string patient_id = params[0];
    Person* patient = nullptr;

    if( current_patients_.find(patient_id) != current_patients_.end() )
    {
        patient = current_patients_[patient_id];
    }
    else if( all_patients_.find(patient_id) != all_patients_.end() )
    {
        patient = all_patients_[patient_id];
    }
    else
    {
        std::cout << CANT_FIND << patient_id << std::endl;
        return;
    }

    for( Care_Period* care_period : patient_care_periods_[patient_id] )
    {
        care_period->print_patient_info();
    }
    patient->print_medicines("  - ");
}

void Hospital::print_care_periods(Params params)
{
    std::string staff_member_id = params[0];
    if( staff_.find(staff_member_id) != staff_.end() )
    {
        if( staff_care_periods_[staff_member_id].empty() )
        {
            std::cout << "None" << std::endl;
            return;
        }
        for( Care_Period* care_period : staff_care_periods_[staff_member_id] )
        {
            care_period->print_staff_info();
        }
    }
    else
    {
        std::cout << CANT_FIND << staff_member_id << std::endl;
    }
}

void Hospital::print_all_medicines(Params)
{
    if( assigned_medicine_.empty() )
    {
        std::cout << "None" << std::endl;
    }
    else
    {
        for( const auto& medicine : assigned_medicine_ )
        {
            std::cout << medicine.first << " prescribed for" << std::endl;

            for( Person* patient : medicine.second )
            {
                std::cout << "* " << patient->get_id() << std::endl;
            }
        }
    }
}

void Hospital::print_all_patients(Params)
{
    if( all_patients_.empty() )
     {
       std::cout << "None" << std::endl;
    }
    else
    {
        for( const auto& patient : all_patients_ )
        {
            std::cout << patient.first << std::endl;
            print_patient_info({patient.first});
        }
    }
}

void Hospital::print_current_patients(Params)
{
    if( current_patients_.empty() )
    {
       std::cout << "None" << std::endl;
    }
    else
    {
        for( const auto& patient : current_patients_ )
        {
            std::cout << patient.first << std::endl;
            print_patient_info({patient.first});
        }
    }
}

