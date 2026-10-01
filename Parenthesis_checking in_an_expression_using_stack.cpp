#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string exp)
{
    stack<char> s;

    for (char ch : exp)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string exp;

    cout << "Enter an expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Parentheses are balanced." << endl;
    else
        cout << "Parentheses are not balanced." << endl;

    return 0;
}

