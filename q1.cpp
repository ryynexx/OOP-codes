#include <iostream>
using namespace std;
int duplicate(int* arr1, int* arr2);
int common(int* arr1, int* arr2);
int main()
{
  int* arr1= new int[5];
  int* arr2= new int[5];
  
  int count1;
  int count2;

  int val1[]={54, 2, 37, 7, 45};
  int val2[]={51, 2, 45, 1, 6};

  for(int i=0; i<5; i++)
  {
    arr1[i]= val1[i];
    arr2[i]= val2[i];
  }
  
  count1 = duplicate(arr1, arr2);
  count2 = common(arr1, arr2);

  cout<<"The number of same values at same locations are: "<< count1 <<"\n";
  cout<< "The number of same values in both arrays are: "<< count2 <<"\n";

  delete[] arr1, arr2;
  arr1 = NULL;
  arr2 = NULL;

return 0;
}
int duplicate(int* arr1, int* arr2)
{ 
  int count=0;  
    for(int i=0; i<5; i++)
    {
       if(arr1[i]==arr2[i])
       {
         count++;
       }
    }

    return count;

}
int common(int* arr1, int* arr2)
{
    int count=0;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
           if( arr1[i] == arr2[j])
           {
             count++;
           }
        }
    }

    return count;
}