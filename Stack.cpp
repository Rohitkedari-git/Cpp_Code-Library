#include <iostream>
using namespace std;

#define MAX 5

class Stack {
public:
    int A[MAX];
    int top;

    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack is Overflow" << endl;
        }
        else {
            top++;
            A[top] = value;
            cout << value << " is pushed into stack" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Underflow" << endl;
        }
        else {
            cout << A[top] << " is popped from stack" << endl;
            top--;   // Remove the top element
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << A[i] << endl;
            }
        }
    }
};

int main() {
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    
    cout << "******\n";
    s1.display();
    cout << "******\n";
    
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    s1.push(40);

    cout << "******\n";
    s1.display();
    cout << "******\n";
    

    return 0;
}
