#include <iostream>
#include "Savings_Account.h"
#include "Current_Account.h"

int main() {
    Savings_Account savings("S123", "John Doe", 1000, 0.02);
    Current_Account current("C456", "Jane Doe", 2000, 500);

    std::cout << savings << "\n";
    std::cout << current << "\n";

    savings.deposit(500);
    current.withdraw(1000);

    std::cout << "Account details after deposits and withdrawls:\n";
    std::cout << savings << "\n";
    std::cout << current << "\n";

    current = current + savings;

    std::cout << "Account details after transfer:\n";
    std::cout << savings << "\n";
    std::cout << current << "\n";

    return 0;
}