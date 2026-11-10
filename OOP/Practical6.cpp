// Experiment 6: File Input and Output Operations
#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string filename = "sample_output.txt";

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create or open the output file." << std::endl;
        return 1;
    }

    std::cout << "Writing data to '" << filename << "'...\n";
    outFile << "Line 1: Hello, C++ File I/O!\n";
    outFile << "Line 2: Demonstration of writing to a file.\n";
    outFile << "Line 3: Storing integer value = " << 100 << "\n";
    outFile << "Line 4: NMIET " << "\n";
    

    outFile.close();
    std::cout << "File closed successfully after writing.\n\n";

    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
        return 1;
    }

    std::cout << "--- Contents of '" << filename << "' ---" << std::endl;

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
    std::cout << "------------------------------------------------" << std::endl;

    return 0;
}
