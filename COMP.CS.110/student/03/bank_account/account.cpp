#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    name_(owner), balance_(0), credit_(has_credit), credit_limit_(0)
{
    generate_iban();
}

int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}

std::string Account::get_iban() const
{
    return iban_;
}

std::string Account::get_name() const
{
    return name_;
}

int Account::get_balance() const
{
    return balance_;
}

void Account::print() const
{
    std::cout
    << Account::get_name() << " : "
    << Account::get_iban() << " : "
    << Account::get_balance() << " euros" << std::endl;
}

void Account::set_credit_limit(int limit)

{
    if ( credit_ )
    {
        credit_limit_ = limit;
    }
    else
    {
        std::cout
        << "Cannot set credit limit: the account has no credit card"
        << std::endl;
    }
}

void Account::save_money(int amount)
{
    balance_ = get_balance() + amount;
}

void Account::take_money(int amount)
{
    if ( balance_ + credit_limit_ < amount )
    {
       if ( credit_ )
       {

           std::cout << "Cannot take money: credit limit overflow" << std::endl;
       }
       else
       {
           std::cout << "Cannot take money: balance underflow" << std::endl;
       }
    }
    else
    {
        balance_ = get_balance() - amount;
        std::cout << amount << " euros taken: new balance of "
        << get_iban() << " is " << get_balance() << " euros"
        << std::endl;
    }
}

void Account::transfer_to(Account & target_account, int amount)

{
    if ( balance_ + credit_limit_ < amount )
    {
       if ( credit_ )
       {

           std::cout << "Cannot take money: credit limit overflow" << std::endl;
           std::cout << "Transfer from " << get_iban() << " failed" << std::endl;
       }
       else
       {
           std::cout << "Cannot take money: balance underflow" << std::endl;
           std::cout << "Transfer from " << get_iban() << " failed" << std::endl;
       }
    }
    else
    {
        balance_ = get_balance() - amount;
        target_account.balance_ = target_account.get_balance() + amount;

        std::cout << amount << " euros taken: new balance of "
        << get_iban() << " is "
        << get_balance() << " euros" << std::endl;
    }
}
