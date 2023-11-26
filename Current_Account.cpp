#include <iomanip>
#include "Current_Account.h"

void Current_Account::display_details() noexcept {
    std::cout << std::fixed << std::showpoint;
    std::cout << "Account Details for Current Account (ID: " << _account_number << "):\n"
        << "  Holder: " << _account_holder << "\n"
        << "  Balance: $" << std::setprecision(2) << _balance << "\n"
        << "  Overdraft Limit: $" << _overdraft_limit << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Current_Account& a) {
    return os << std::fixed << std::showpoint
        << "Account Details for Current Account (ID: " << a._account_number << "):\n"
        << "  Holder: " << a._account_holder << "\n"
        << "  Balance: $" << std::setprecision(2) << a._balance << "\n"
        << "  Overdraft Limit: $" << a._overdraft_limit << std::endl;
}

double Current_Account::withdraw(double amount) noexcept {
    if (amount < (_balance + _overdraft_limit)) {
        _balance -= amount;
        return amount;
    }

    return 0.0;
}

Current_Account Current_Account::operator+(Account& rhs) {
    Current_Account new_account = Current_Account(_account_number, _account_holder, _balance, _overdraft_limit);
    new_account.deposit(rhs.withdraw_all());
    return new_account;
}