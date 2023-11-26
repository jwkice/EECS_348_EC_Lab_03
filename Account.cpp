#include "Account.h"

void Account::deposit(double amount) noexcept {
    _balance += amount;
}

double Account::withdraw(double amount) noexcept {
    if (amount < _balance) {
        _balance -= amount;
        return amount;
    }

    return 0.0;
}

double Account::withdraw_all() noexcept {
    double balance = _balance;
    _balance = 0;
    return balance;
}