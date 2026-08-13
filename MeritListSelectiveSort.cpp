#include <iostream>
#include <string>
using namespace std;


struct Student {
    int rollNo;
    string name;
    float cgpa; 
};

int main() {
  
    Student arr[] = {
        {101, "Ayush", 8.5f},
        {102, "Bunty", 9.1f},
        {103, "Chetan", 7.8f},
        {104, "Deva", 9.6f},
        {105, "Mohit", 8.9f},
        {106, "Sumit", 9.2f},
        {107, "Ashwin", 9.2},
        {108, "Rohit", 8.09},
        {109, "Aditya", 9.9}
    };
    int n = 6; 

    for (int i = 0; i < n - 1; i++) {
        
        int maxIndex = i; 
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j].cgpa > arr[maxIndex].cgpa) {
                maxIndex = j; 
            }
        }
        
    
        swap(arr[i], arr[maxIndex]);
    }

    cout << "=========================================" << endl;
    cout << "        TOP 5 STUDENTS MERIT LIST        " << endl;
    cout << "=========================================" << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". Roll No: " << arr[i].rollNo 
             << " \t| Name: " << arr[i].name 
             << " \t| CGPA: " << arr[i].cgpa << endl;
    }
    
    cout << "=========================================" << endl;


cout << "The Merit List is Displayed";
    return 0;
}
