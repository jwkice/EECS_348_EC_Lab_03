#include <iomanip>
#include "Savings_Account.h"

void Savings_Account::display_details() noexcept {
    std::cout << std::fixed << std::showpoint;
    std::cout << "Account Details for Savings Account (ID: " << _account_number << "):\n"
        << "  Holder: " << _account_holder << "\n"
        << "  Balance: $" << std::setprecision(2) << _balance << "\n"
        << "  Interest Rate: " << _interest_rate*100 << "%" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Savings_Account& a) {
    return os << std::fixed << std::showpoint
        << "Account Details for Savings Account (ID: " << a._account_number << "):\n"
        << "  Holder: " << a._account_holder << "\n"
        << "  Balance: $" << std::setprecision(2) << a._balance << "\n"
        << "  Interest Rate: " << a._interest_rate*100 << "%" << std::endl;
}

double Savings_Account::withdraw(double amount) noexcept {
    double temp_balance = _balance - amount;
    if (temp_balance >= _minimum_balance) {
        _balance -= amount;
        return amount;
    }
    else {
        double difference = _minimum_balance - temp_balance;
        double new_amount = amount - difference;
        _balance -= new_amount;
        return new_amount;
    }
}

double Savings_Account::withdraw_all() noexcept {
    double amount = _balance - _minimum_balance;
    _balance = _balance - amount;
    return amount;
}

Savings_Account Savings_Account::operator+(Account& rhs) {
    Savings_Account new_account = Savings_Account(_account_number, _account_holder, _balance, _interest_rate);
    new_account.deposit(rhs.withdraw_all());
    return new_account;
}