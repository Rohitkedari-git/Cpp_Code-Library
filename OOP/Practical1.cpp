// Experiment 1: Complex Number Operations using Operator Overloading
#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    // Default Constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator +(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Overload * operator
    Complex operator *(Complex c)
    {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }

    // Overload >> operator
    friend istream& operator >>(istream& in, Complex& c);

    // Overload << operator
    friend ostream& operator <<(ostream& out, Complex& c);
};

// Definition of >> operator
istream& operator >>(istream& in, Complex& c)
{
    cout << "Enter Real Part : ";
    in >> c.real;

    cout << "Enter Imaginary Part : ";
    in >> c.imag;

    return in;
}

// Definition of << operator
ostream& operator <<(ostream& out, Complex& c)
{
    out << c.real;

    if (c.imag >= 0)
        out << "+" << c.imag << "i";
    else
        out << c.imag << "i";

    return out;
}

// Main Function
int main()
{
    Complex c1, c2, sum, product;

    cout << "Enter First Complex Number" << endl;
    cin >> c1;

    cout << "\nEnter Second Complex Number" << endl;
    cin >> c2;

    sum = c1 + c2;
    product = c1 * c2;

    cout << "\nFirst Complex Number = " << c1 << endl;
    cout << "Second Complex Number = " << c2 << endl;

    cout << "\nAddition = " << sum << endl;
    cout << "Multiplication = " << product << endl;

    return 0;
}
