#include <iostream>
using namespace std;
int main()
{
  int A[5],i,min;
  cout << "\n Enter Array Elements:";
  for (i=0;i<5;i++)
  {
    cin >> A[i];
  }
  min = A[0];
  cout << "\n Array Elements are :";
  for (i=0;i<5;i++)
  {
    cout << A[i] << "\t";
  }
  //Logic for min 
  for (i=0;i<5;i++)
  {
    if (A[i]<min)
    {
      min = A[i];
    }
  }
  cout << "\n Minimun Element is :" << min;
  
return 0;
}
