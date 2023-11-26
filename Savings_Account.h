#ifndef __SAVINGS_ACCOUNT_H__
#define __SAVINGS_ACCOUNT_H__
#include "Account.h"

class Savings_Account : public Account {
public:
    Savings_Account(std::string account_number, std::string account_holder, double balance, double interest_rate)
        : Account(account_number, account_holder, balance), _interest_rate(interest_rate) {}

    virtual void display_details() noexcept override;
    double withdraw(double amount) noexcept;
    double withdraw_all() noexcept;
    [[nodiscard]] Savings_Account operator+(Account& rhs);
private:
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& a);
private:
    double _interest_rate = 0.0;
    double _minimum_balance = 1200.0;
};

#endif