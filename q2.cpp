#include <iostream>
using namespace std;
void swap(int* val1, int* val2);
int main()
{
   int* num1= new int;
   int* num2= new int;
  
   cout<<"Enter 1st and 2nd number: ";
   cin >> *(num1) >> *(num2);

   cout<<"\n1st number : "<< *(num1) << "\n 2nd number : "<<*(num2)<<"\n";

   swap(num1, num2);

   cout<<"After swapping \n";
   cout<<"\n1st number : "<< *(num1) << "\n 2nd number : "<<*(num2)<<"\n";

  delete num1, num2;
  num1 = NULL;
  num2 = NULL;

 return 0;
}
void swap(int* val1, int* val2)
{
    int swap;
    
    swap = *(val1);
    *(val1) = *(val2);
    *(val2) = swap;
}