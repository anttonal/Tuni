#include "book.hh"


Book::Book( std::string const& author, std::string const& title ):
    author_(author), title_(title), loaned_(false),
    loan_date_(Date()), return_date_(Date())
{
}

std::string Book::get_author()
{
    return author_;
}

std::string Book::get_title()
{
    return title_;
}

void Book::print_loaned()
{
    loan_date_.print();
}

void Book::print_return_date()
{
    return_date_.print();
}

void Book::print()
{
    std::cout << get_author() << " : " << get_title() << std::endl;
    if ( loaned_ )
    {
        std::cout << "- loaned: ";
        loan_date_.print();
        std::cout << "- to be returned: ";
        return_date_.print();
    }
    else
    {
        std::cout << "- available" << std::endl;

    }
}

void Book::loan(Date today)
{
    if ( loaned_ )
    {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
    }
    else
    {
        loaned_ = true;
        loan_date_ = today;
        today.advance(28);
        return_date_ = today;

    }
}

void Book::renew()
{
    if ( loaned_ )
    {
        return_date_.advance(28);
    }
    else
    {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
    }

}

void Book::give_back()
{
    loaned_ = false;
    loan_date_ = Date();
    return_date_ = Date();
}
