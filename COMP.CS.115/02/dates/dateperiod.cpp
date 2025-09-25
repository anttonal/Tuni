#include "dateperiod.hh"

DatePeriod::DatePeriod(const Date &d1, const Date &d2) :
    start_(d1), end_(d2){}

DatePeriod::~DatePeriod()
{}

string DatePeriod::getStart()
{
    return start_.toIsoFormat();
}

string DatePeriod::getEnd()
{
    return end_.toIsoFormat();
}

unsigned int DatePeriod::getDiff() {
    unsigned int diff = 0;

    int startYear = start_.getYear();
    int startMonth = start_.getMonth();
    int startDay = start_.getDay();
    int endYear = end_.getYear();
    int endMonth = end_.getMonth();
    int endDay = end_.getDay();

    auto isLeapYear = [](int year) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    };

    if (startYear == endYear) {
        if (startMonth == endMonth) {
            diff = endDay - startDay;
        } else {
            for (int month = startMonth; month < endMonth; ++month) {
                if (month == 2) {
                    diff += (isLeapYear(startYear) ? 29 : 28);
                } else {
                    diff += MONTH_SIZES[month - 1];
                }
            }
            diff += endDay - startDay;
        }
    } else {
        for (int month = startMonth; month <= 12; ++month) {
            if (month == 2) {
                diff += (isLeapYear(startYear) ? 29 : 28);
            } else {
                diff += MONTH_SIZES[month - 1];
            }
        }
        diff -= startDay;

        for (int year = startYear + 1; year < endYear; ++year) {
            diff += (isLeapYear(year) ? 366 : 365);
        }

        for (int month = 1; month < endMonth; ++month) {
            if (month == 2) {
                diff += (isLeapYear(endYear) ? 29 : 28);
            } else {
                diff += MONTH_SIZES[month - 1];
            }
        }
        diff += endDay;
    }

    return diff;
}
