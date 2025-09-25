#include "datetime.hh"



DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
    : Date(year, month, day), hour_(hour), minute_(minute), second_(second)
{
    std::string secondd = (second_ < 10 ? "0" : "") + std::to_string(second_);
    std::string minutee = (minute_ < 10 ? "0" : "") + std::to_string(minute_);
    std::string hourr = (hour_ < 10 ? "0" : "") + std::to_string(hour_);
    std::string result = hourr + ":" + minutee + ":" + secondd;

    if (!isValid()){
        std::string message = "Illegal time " + result;
        throw DateException(message.c_str());
    }
}

DateTime::~DateTime()
{}

int DateTime::getHour()
{
    return hour_;
}

int DateTime::getMinute()
{
    return minute_;
}

int DateTime::getSecond()
{
    return second_;
}

std::string DateTime::toString()
{
    std::string second = (second_ < 10 ? "0" : "") + std::to_string(second_);
    std::string minute = (minute_ < 10 ? "0" : "") + std::to_string(minute_);
    std::string hour = (hour_ < 10 ? "0" : "") + std::to_string(hour_);

    std::string result = Date::toString() + " " + hour + ":" + minute + ":" + second;

    return result;
}

bool DateTime::isValid() const
{
    return (hour_ >= 0 && hour_ <= 23) &&
           (minute_ >= 0 && minute_ <= 59) &&
           (second_ >= 0 && second_ <= 59);
}
