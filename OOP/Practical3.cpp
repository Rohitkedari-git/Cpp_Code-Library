// Experiment 3: Publication Management & Exception Handling
#include<iostream>
#include<string>
using namespace std;

class publications
{
protected:
    float price;
    string title;

public:
    void details()
    {
        try
        {
            cout << "Enter the title: ";
            cin >> ws;
            getline(cin, title);

            cout << "Enter price: ";
            cin >> price;

            if(price < 0)
                throw price;
        }
        catch(...)
        {
            cout << "Invalid price entered!" << endl;
            setting_zero();
        }
    }

    void display()
    {
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }

    void setting_zero()
    {
        title = "Invalid";
        price = 0;
    }
};

class book : public publications
{
private:
    int pagecount;

public:
    void details_book()
    {
        details();

        try
        {
            cout << "Enter page count: ";
            cin >> pagecount;

            if(pagecount < 0)
                throw pagecount;
        }
        catch(...)
        {
            cout << "Invalid page count entered!" << endl;
            pagecount = 0;
        }
    }

    void display_book()
    {
        cout << "\n********** BOOK DETAILS **********" << endl;
        display();
        cout << "Page Count : " << pagecount << endl;
    }
};

class disc : public publications
{
private:
    int time;

public:
    void details_disc()
    {
        details();

        try
        {
            cout << "Enter playing time (minutes): ";
            cin >> time;

            if(time < 0)
                throw time;
        }
        catch(...)
        {
            cout << "Invalid playing time entered!" << endl;
            time = 0;
        }
    }

    void display_disc()
    {
        cout << "\n********** DISC DETAILS **********" << endl;
        display();
        cout << "Playing Time : " << time << " minutes" << endl;
    }
};

int main()
{
    book b;
    disc d;

    cout << "Enter Book Details" << endl;
    b.details_book();

    cout << "\nEnter Disc Details" << endl;
    d.details_disc();

    cout << "\nDisplaying Details\n";

    b.display_book();
    d.display_disc();

    return 0;
}
