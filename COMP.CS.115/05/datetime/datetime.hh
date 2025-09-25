#ifndef DATETIME_HH
#define DATETIME_HH
#include "date.hh"

class DateTime : public Date
{
public:
    DateTime(int year, int month, int day, int hour, int minute, int second);

    virtual ~DateTime();

    int getHour();

    int getMinute();

    int getSecond();

    std::string toString();

private:
    int hour_;
    int minute_;
    int second_;

    bool isValid() const;
};

#endif // DATETIME_HH
