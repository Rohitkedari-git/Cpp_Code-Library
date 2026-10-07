#include<iostream>
using namespace std;
class Queue
{
public:
  int A[5];
  int front;
  int rear;
  
  Queue()
  {
    front = -1;
    rear = -1;
  }
  void enQueue(int value)
  {
    if(rear == 4)
    {  
      cout<<"Queue Overflow"<<endl;
    }
    if(front == -1)
    {
      front = 0;
    }
    rear++;
    A[rear] = value;
    cout<<value<<" is added to Queue\n ";
  }
  void deQueue()
  {
        if(rear == -1)
    {
      cout<<" QUEUE is Empty\n ";
    }
    else
    {   
      cout<<A[front]<<" is removed from the QUEUE \n";
      front++;
    }
  }
  void Display()
  {
    if(rear == -1)
    {
      cout<<" QUEUE is Empty ";
    }
    else
    {
      cout<<" The Queue is: ";
      for(int i = front; i<= rear ; i ++)
      {
        cout<<A[i]<<"\n";
      }
    }
  }
};
int main()
{
  Queue q;
  q.enQueue(28);
  q.enQueue(29);
  q.enQueue(30);
  q.enQueue(31);
  q.enQueue(32);
  q.enQueue(33);
  
  q.Display();
  
  q.deQueue();
  q.deQueue();
  q.deQueue();
  q.deQueue();
  q.deQueue();
  
  return 0;
}
  
