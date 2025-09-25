#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    Account(const std::string& owner, bool has_credit = false);

    void print() const;
    void set_credit_limit(int limit);
    void save_money(int amount);
    void take_money(int amount);
    void transfer_to(Account & target_account, int amount);

private:

    std::string iban_;
    std::string name_;
    int balance_;
    bool credit_;
    int credit_limit_;
    static int running_number_;

    std::string get_iban() const;
    std::string get_name() const;
    int get_balance() const;
    void generate_iban();

};

#endif // ACCOUNT_HH
