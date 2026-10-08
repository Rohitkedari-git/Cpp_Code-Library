#include <iostream>
using namespace std;

class BusPassQueue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor to initialize the queue
    BusPassQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~BusPassQueue() {
        delete[] arr;
    }

    // c. Detect queue empty condition
    bool isEmpty() {
        return (front == -1);
    }

    // c. Detect queue full condition
    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    // a. Insert student IDs in circular queue (Enqueue)
    void enqueue(int studentId) {
        if (isFull()) {
            cout << "\nQueue is FULL! Cannot add more student IDs right now.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = studentId;
        cout << "\nSuccess: Student ID " << studentId << " added to the queue.\n";
    }

    // b. Delete student ID as pass is issued (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY! No pending bus pass requests.\n";
            return;
        }
        cout << "\nSuccess: Bus pass issued to Student ID: " << arr[front] << "\n";
        
        if (front == rear) {
            // Queue has only one element, reset after removal
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    // d. Display the circular queue
    void display() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY! No students in the queue.\n";
            return;
        }
        cout << "\nCurrent Bus Pass Queue (Front to Rear):\n[ ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << "]\n";
    }
};

int main() {
    int capacity;
    cout << "Enter the maximum capacity of the bus pass queue: ";
    cin >> capacity;

    BusPassQueue queue(capacity);
    int choice, studentId;

    do {
        cout << "\n--- Bus Pass Distribution System ---\n";
        cout << "1. Insert Student ID (Enqueue)\n";
        cout << "2. Issue Bus Pass & Remove ID (Dequeue)\n";
        cout << "3. Check if Queue is Full\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> studentId;
                queue.enqueue(studentId);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                if (queue.isFull())
                    cout << "\nStatus: The queue is FULL.\n";
                else
                    cout << "\nStatus: The queue is NOT full.\n";
                break;
            case 4:
                if (queue.isEmpty())
                    cout << "\nStatus: The queue is EMPTY.\n";
                else
                    cout << "\nStatus: The queue is NOT empty.\n";
                break;
            case 5:
                queue.display();
                break;
            case 6:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
