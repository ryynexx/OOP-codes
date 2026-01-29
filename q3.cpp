#include <iostream>
using namespace std;
void reverse (int* arr, int siz);
int main()
{   
    int size;
    cout<<"Enter size of array: ";
    cin>> size;

    int* arr = new int[size];
    cout<<"\nEnter elements of array: \n";
        for(int i=0; i<size; i++)
        {
            cin>> *(arr+i);
        }
    
    reverse(arr, size);
    
    cout<<"\nAfter reversing array: \n";
        for(int j=0; j<size; j++)
        {
            cout<<*(arr+j)<<" ";
        }
        cout<<"\n";

      delete[] arr;
      arr = NULL;
      
    return 0;  
}
void reverse(int* arr, int siz)
{
    int swap;

    for(int i=0; i<siz/2; i++)
    {
        swap = *(arr+i);
        *(arr + i)=*(arr+(siz-1-i));
        *(arr+(siz-1-i)) = swap;
    }
}
