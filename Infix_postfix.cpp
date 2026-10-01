#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;
            }

            s.push(result);
        }
    }

    return s.top();
}

int main()
{
    string infix, postfix;

    cout << "Enter marks calculation expression: ";
    cin >> infix;

    postfix = infixToPostfix(infix);

    cout << "Infix Expression   : " << infix << endl;
    cout << "Postfix Expression : " << postfix << endl;

    int result = evaluatePostfix(postfix);

    cout << "Result              : " << result << endl;

    return 0;
}
