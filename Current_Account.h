#ifndef __CURRENT_ACCOUNT_H__
#define __CURRENT_ACCOUNT_H__
#include "Account.h"

class Current_Account : public Account {
public:
    Current_Account(std::string account_number, std::string account_holder, double balance, double overdraft_limit)
        : Account(account_number, account_holder, balance), _overdraft_limit(overdraft_limit) {}

    virtual void display_details() noexcept override;
    virtual double withdraw(double amount) noexcept override;
    [[nodiscard]] Current_Account operator+(Account& rhs);
private:
    friend std::ostream& operator<<(std::ostream& os, const Current_Account& a);
private:
    double _overdraft_limit = 0.0;
};

#endif