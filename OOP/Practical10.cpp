// Experiment 10: ATM Machine Simulation & Exception Handling
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

// Custom exception for insufficient funds
class ArithmeticException : public runtime_error {
public:
  ArithmeticException(const string &message) : runtime_error(message) {}
};

// Custom exception for invalid input
class IllegalArgumentException : public invalid_argument {
public:
  IllegalArgumentException(const string &message) : invalid_argument(message) {}
};

class ATM {
private:
  double balance;

public:
  ATM(double initialBalance) { balance = initialBalance; }

  void checkBalance() {
    cout << "\nCurrent Account Balance: Rs. " << balance << endl;
  }

  void deposit(double amount) {
    if (amount <= 0) {
      throw IllegalArgumentException(
          "Deposit amount must be greater than zero.");
    }

    balance += amount;

    cout << "Rs. " << amount << " deposited successfully.\n";
    cout << "Updated Balance: Rs. " << balance << endl;
  }

  void withdraw(double amount) {
    if (amount <= 0) {
      throw IllegalArgumentException(
          "Withdrawal amount must be greater than zero.");
    }

    if (amount > balance) {
      throw ArithmeticException("Insufficient funds.");
    }

    balance -= amount;

    cout << "Rs. " << amount << " withdrawn successfully.\n";
    cout << "Remaining Balance: Rs. " << balance << endl;
  }
};

int main() {
  ATM atm(10000);
  int choice;
  double amount;

  cout << "====================================\n";
  cout << "        ATM MACHINE SIMULATION      \n";
  cout << "====================================\n";

  while (true) {
    cout << "\n------------ ATM MENU ------------\n";
    cout << "1. Check Account Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "-----------------------------------\n";
    cout << "Enter your choice: ";

    try {
      cin >> choice;

      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        throw IllegalArgumentException(
            "Invalid input. Enter a number from 1 to 4.");
      }

      switch (choice) {
      case 1:
        atm.checkBalance();
        break;

      case 2:
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          throw IllegalArgumentException("Invalid deposit amount.");
        }

        atm.deposit(amount);
        break;

      case 3:
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          throw IllegalArgumentException("Invalid withdrawal amount.");
        }

        atm.withdraw(amount);
        break;

      case 4:
        cout << "\nThank you for using the ATM.\n";
        return 0;

      default:
        throw IllegalArgumentException("Invalid choice. Please select 1 to 4.");
      }
    } catch (const ArithmeticException &e) {
      cout << "\nArithmetic Exception: " << e.what() << endl;
    } catch (const IllegalArgumentException &e) {
      cout << "\nIllegal Argument Exception: " << e.what() << endl;
    } catch (const exception &e) {
      cout << "\nException: " << e.what() << endl;
    }

    // Finally equivalent in C++
    cout << "\nTransaction completed.\n";
    cout << "ATM is ready for the next transaction.\n";
  }

  return 0;
}
