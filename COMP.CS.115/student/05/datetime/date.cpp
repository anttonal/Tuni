#include "date.hh"

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day)
{
    if (!isValid()){
        std::string message = "Illegal date " + Date::toString();
        throw DateException(message.c_str());
    }
}

Date::~Date()
{}

int Date::getYear()
{
    return year_;
}

int Date::getMonth()
{
    return month_;
}

int Date::getDay()
{
    return day_;
}

std::string Date::toString()
{
    std::string day = (day_ < 10 ? "0" : "") + std::to_string(day_);
    std::string month = (month_ < 10 ? "0" : "") + std::to_string(month_);
    std::string year = std::to_string(year_);

    std::string result = day + "." + month + "." +year;
    return result;
}

bool Date::isLeapYear() const
{
    return (year_ % 4 == 0) and ((year_ % 100 != 0) or (year_ % 400 == 0));
}

bool Date::isValid()
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
