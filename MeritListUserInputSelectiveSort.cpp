#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float cgpa; 
};

int main() {
    int n;
    cout << "Enter the total number of students: ";
    cin >> n;

    Student arr[50];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Student " << i + 1 << " ---" << endl;
        cout << "Enter Roll Number: ";
        cin >> arr[i].rollNo;
        cout << "Enter Name (Without spaces): ";
        cin >> arr[i].name;
        cout << "Enter CGPA: ";
        cin >> arr[i].cgpa;
    }

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j].cgpa > arr[maxIndex].cgpa) {
                maxIndex = j; 
            }
        }
        swap(arr[i], arr[maxIndex]);
    }

    cout << "\n=========================================" << endl;
    cout << "        TOP 5 STUDENTS MERIT LIST        " << endl;
    cout << "=========================================" << endl;
    
    
    for (int i = 0; i < n; i++) {
        if (i == 5) {
            break;
        }
        cout << i + 1 << ". Roll No: " << arr[i].rollNo 
             << " \tName: " << arr[i].name 
             << " \tCGPA: " << arr[i].cgpa << endl;
    }
    cout << "=========================================" << endl;

    return 0;
}
