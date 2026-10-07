#include <iostream>
using namespace std;

class Queue
{
    int queue[20];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue()
    {
        int token;

        if (rear == 19)
        {
            cout << "Queue is full\n";
            return;
        }

        cout << "Enter token number: ";
        cin >> token;

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = token;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Processed token: " << queue[front] << endl;
            front++;

            if (front > rear)
                front = rear = -1;
        }
    }

    void displayFrontRear()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Front: " << queue[front] << endl;
            cout << "Rear: " << queue[rear] << endl;
        }
    }

    void displayQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue: ";

            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";

            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Display Front and Rear\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.enqueue();
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.displayQueue();
                break;

            case 4:
                q.displayFrontRear();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
