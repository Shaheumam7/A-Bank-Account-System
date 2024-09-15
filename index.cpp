#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class BankAccount {
private:
    int accountNumber;
    std::string name;
    double balance;
    std::vector<std::string> history;

public:
    BankAccount(int accountNumber, std::string name, double initialBalance)
        : accountNumber(accountNumber), name(std::move(name)), balance(initialBalance) {
        history.push_back("Account created with initial balance " + formatAmount(initialBalance));
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back("Deposited " + formatAmount(amount));
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            history.push_back("Withdrawn " + formatAmount(amount));
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    std::vector<std::string> getHistory() const {
        return history;
    }

private:
    static std::string formatAmount(double amount) {
        std::ostringstream oss;
        oss.precision(2);
        oss << std::fixed << amount;
        return oss.str();
    }
};

int main() {
    // Create a new bank account
    BankAccount account(12345, "John Doe", 1000.0);

    // Deposit and withdraw money
    account.deposit(500.0);
    account.withdraw(200.0);
    account.deposit(300.0);

    // Display account balance and history
    std::cout << "Account Balance: $" << account.getBalance() << std::endl;
    for (const auto& transaction : account.getHistory()) {
        std::cout << transaction << std::endl;
    }

    return 0;
}
