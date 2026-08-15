#include <iostream>

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    // Parameterized constructor to initialize private members
    BankAccount(std::string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    // Declaration of the friend function inside the class
    friend void displayAndBonus(BankAccount &account);
};

// Definition of the friend function outside the class (No 'friend' keyword here)
void displayAndBonus(BankAccount &account) {
    // Accessing private members directly using the object name and dot operator
    std::cout << "Account Holder: " << account.accountHolder << std::endl;
    std::cout << "Current Balance: $" << account.balance << std::endl;

    // Modifying a private data member
    account.balance += 500.0; 
    std::cout << "New Balance after Bonus: $" << account.balance << std::endl;
}

int main() {
    // Creating an object of BankAccount
    BankAccount userAccount("Alice Smith", 2500.0);

    // Calling the friend function like a normal global function (No object dot prefix)
    displayAndBonus(userAccount);

    return 0;
}
