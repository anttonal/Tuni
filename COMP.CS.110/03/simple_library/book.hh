#ifndef BOOK_HH
#define BOOK_HH
#include <string>
#include <iostream>
#include "date.hh"
class Book
{
public:
    Book( std::string const& author, std::string const& title );

    void print();
    void loan(Date today);
    void renew();
    void give_back();


private:

    std::string author_;
    std::string title_;
    bool loaned_;
    Date loan_date_;
    Date return_date_;

    std::string get_author();
    std::string get_title();
    void print_loaned();
    void print_return_date();
};


#endif // BOOK_HH
