#include <iostream>
#include <string>

int main() {
    // Variable to store the user's input
    std::string userName;

    // Prompting the user for input
    std::cout << "Enter your name: ";
    
    // Reading a full line of text (including spaces)
    std::getline(std::cin, userName);

    // Outputting a personalized message
    std::cout << "Hello, " << userName << "! Welcome to C++ programming." << std::endl;

    // Indicating that the program completed successfully
    return 0;
}
