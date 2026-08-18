#include<iostream>
using namespace std;
int main()
{
  int A[]={562,512,671,812,954};
  int flightno,i,flag=0;

  cout<<"\n Flights are:";
  for(i=0;i<5;i++)
  {
    cout<<A[i]<<"\t";
  }

  cout<<"\n Enter Flight no to be searched:";
  cin>>flightno;//221

  for(i=0;i<5;i++)
  {
    if(A[i]==flightno)//221==221
    {
      flag=1;
    }
  }

  if(flag==1)
    cout<<"\n Flight "<<flightno<<" is found";// "flight no " <<flightno << "is found"
  else
    cout<<"\n Flight "<<flightno<<" is not found";

  return 0;
}
