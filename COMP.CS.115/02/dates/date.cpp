#include "date.hh"

//TODO: Implement other functions here

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

Date::~Date()
{

}

int Date::getYear() const
{
    return year_;
}

int Date::getMonth() const
{
    return month_;
}

int Date::getDay() const
{
    return day_;
}

string Date::toString() const
{ // dd.mm.yyyy
    return to_string(day_) + "." + to_string(month_) + "." + to_string(year_);
}

string Date::toIsoFormat() const
{ // yyyy-mm-dd
    string iso_date = to_string(year_) + "-";
    if (month_ < 10){
        iso_date = iso_date + "0" + to_string(month_) + "-";
    }
    else {
        iso_date = iso_date + to_string(month_) + "-";
    }
    if (day_ < 10){
        iso_date = iso_date + "0" + to_string(day_);
    }
    else {
        iso_date = iso_date + to_string(day_);
    }
    return iso_date;
}

bool Date::operator<(const Date &other) const {
    // Compare years first
    if (year_ < other.year_) {
        return true;
    }
    if (year_ > other.year_) {
        return false;
    }

    // If years are equal, compare months
    if (month_ < other.month_) {
        return true;
    }
    if (month_ > other.month_) {
        return false;
    }

    // If years and months are equal, compare days
    if (day_ < other.day_) {
        return true;
    }

    return false;
}


bool Date::operator==(const Date &other) const
{

    if (year_ == other.year_)
        if (month_ == other.month_)
            return (day_ == other.day_);
    return false;

}

bool Date::isLeapYear() const
{
    return (year_ % 4 == 0) and ((year_ % 100 != 0) or (year_ % 400 == 0));
}

bool Date::isLegal() const
{
    if (year_ >= FIRST_YEAR && year_ <= LAST_YEAR)
    {
        if (month_ >= 1 && month_ <= 12)
        {
            int max_day = MONTH_SIZES[month_ - 1];

            // Adjust for leap year if February
            if (month_ == 2 && isLeapYear())
            {
                max_day = 29;
            }
            if (day_ >= 1 && day_ <= max_day)
                return true;
        }
    }
    return false;
}


