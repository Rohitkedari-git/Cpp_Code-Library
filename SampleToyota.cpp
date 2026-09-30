#include <iostream>
#include <string>
using namespace std;

// Define a class
class Car {
public:
    string brand;
    int year;

    // Method to display car details
    void displayInfo() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    // Create an object of the Car class
    Car myCar;

    // Assign values to attributes
    myCar.brand = "Toyota";
    myCar.year = 2022;

    // Call the method
    myCar.displayInfo();

    return 0;
}
