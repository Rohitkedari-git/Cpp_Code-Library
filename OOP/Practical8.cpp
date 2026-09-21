#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Library{

private:
    T bookID;
    string bookName;
    string author;
    bool isIssued;

public:
    Library(int id, string name, string auth){
        bookID = id;
        bookName = name;
        isIssued = false;

    }
    void display(){
        cout << Book ID: << bookID << endl;
        cout << Book Name: << bookName << endl;
        cout << Author: << author << endl;
        cout << Status: << endl;
        
        if(isIssued)
            cout << "Issued";
        else
            cout << "Available";
        
        cout << "\n";
    }
    void issueBook()
    {
        if(!issued)
        {
            issued = true;
            cout << "\nBook issued Successfully.";
        }
        else
        {
            cout << "\nBook is already issued."
        }
    }

    void returnBook()
    {
        if (issued)
        {
            issued = false;
            cout << "\nBook returned successfully.";
        }
        else
        {
            cout << "\nBook was not issued.";
        }
    }
};
int main()
{
    Library<int> book1(101,"Object Oriented Programming",
        "Robert Lafore");
    
    Library<string> book2("CS102", "Database Management System",
        "Korth");
    
    
    cout << "====== LIBRARY MANAGEMENT SYSTEM ======\N";

    cout << "\nBook 1 Details:";
    book1.display();
    
    cout << "\nBook 2 Details:";
    book2.display();

    cout << "\n\n--- Book 1 Issue Operation ---";
    book1.issueBook();
    book1.display();

    cout << "\n\n--- Book 1 Return Operation ---";
    book1.returnBook();
    book1.display();
    

    return 0;
}
