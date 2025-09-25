#ifndef DATEPERIOD_HH
#define DATEPERIOD_HH

#include "date.hh"
using namespace std;

class DatePeriod
{
public:
    DatePeriod(const Date& d1, const Date& d2);
    virtual ~DatePeriod();

    string getStart();
    string getEnd();
    unsigned int getDiff();

private:
    Date start_;
    Date end_;
};

#endif // DATEPERIOD_HH
