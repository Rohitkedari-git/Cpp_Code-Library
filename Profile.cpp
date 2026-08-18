#include <iostream>
#include <string>

int main() {
    // 1. Store profile details in variables
    std::string name = "Rohit Prashant Kedari";
    std::string role = "Student at NMIET";
    std::string bio = "Hi! I am learning HTML and building my very first webpage layout.";
    std::string bio2 = "I love coding, technology, and learning new skills.";
    std::string github = "github.com/Rohitkedari-git/Rohitkedari-git";
    std::string email = "rohitkedari017@gmail.com";

    // 2. Draw the layout box in the terminal console
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    
    // Profile image placeholder representation
    std::cout << "|   [IMAGE]  (grey-business-avatar-placeholder)          |" << std::endl; 
    std::cout << "|                                                        |" << std::endl;
    
    // Identity Headers
    std::cout << "|   NAME:  " << name << "                   |" << std::endl;
    std::cout << "|   ROLE:  " << role << "                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    
    // Biography Paragraph
    std::cout << "|   BIO:   " << bio << " |" << std::endl;
    std::cout << "|          " << bio2 << "     |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    
    // Contact Section Links
    std::cout << "|   LINKS:                                               |" << std::endl;
    std::cout << "|   - GitHub:  " << github << " |" << std::endl;
    std::cout << "|   - Email:   " << email << "                  |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "==========================================================" << std::endl;

    return 0;
}
