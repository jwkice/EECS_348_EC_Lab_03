#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <string>

class Account {
public:
    virtual void display_details() noexcept = 0;
    virtual void deposit(double amount) noexcept;
    virtual double withdraw(double amount) noexcept;
    virtual double withdraw_all() noexcept;
protected:
    Account(std::string account_number, std::string account_holder, double balance)
        : _account_number(account_number), _account_holder(account_holder), _balance(balance) {}
protected:
    std::string _account_number = "";
    std::string _account_holder = "";
    double _balance = 0.0;
};

#endif