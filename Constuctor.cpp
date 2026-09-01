#include<iostream>
using namespace std;

class Student
{
    int rollNo;
    protected:
    Student()
    {
        rollNo = 0;
        cout<<"Student default constructor called"<<endl;   
    }

    Student(int r)
    {
        rollNo = r;
        cout<<"Student Parameterized Constructor Called"<<endl;

    }

    Student(const Student& s)
    {
        rollNo = s.rollNo;
        cout<<"Student Copy constructor called"<<endl;

    }
};

class Sports
{
    protected:
        int sportsMarks;

    public:
    Sports()
    {
        sportsMarks = 0;
        cout<<"Sports default constructor called"<<endl;
    }

    Sports(int a)
    {
        sportsMarks = a;
        cout<<"Sports parameterized constructor called"<<endl;

    }

    Sports(const Sports& s)
    {
        sportsMarks = s.sportsMarks;
        cout<<"Sports Copy Constructor Called"<<endl;

    }

    ~Sports()
    {
        cout<<"Sports Destructor Called"<<endl;
        
    }
};

class Result : public Student, public Sports
{
    private:
        int totalMarks;

    public:
        Result() : Student(), Sports()
        {
            totalMarks = 0;
            cout<<"Result default constructor called"<<endl;
        }

        Result(int r ,int s, int  t) : Student(r), Sports(s)
        {
            totalMarks = t;
            cout<<"REsult Parameterized constructor called"<<endl;
        }

        Result(const Result&  obj) : Student(obj), Sports(obj)
        {
            totalMarks = obj.totalMarks;
            cout<<"Result copy construictor calledf "<<endl;
        }

        void display()
        {
            int rollNo
            cout<<"\nRoll No :"<<rollNo;
            cout<<"\nSports Marks :"<<sportsMarks;
            cout<<"\nTotal Marks :"<<totalMarks;
        }

        ~Result()
        {
            cout<<"Result destructor Called "<<endl;
             
        }
};

int main()
{
    cout<<"\n$$$$$$$$$$$$$$Parameterized constructor$$$$$$$$$$$$\n";
    Result r1;
    r1.display();

    cout << "\n*************Copy Constructor***********";
    Result r2(101,25,500);
    r2.display();

    cout<<"\nProgram End....\n";

    return 0;
}
