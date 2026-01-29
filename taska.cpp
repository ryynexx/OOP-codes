#include <iostream>
using namespace std;
bool checkrev(char* str1, char* str2, int s);
int main()
{   
    int size;

    cout<<"Enter size of the strings: ";
    cin>> size; 
    char* str1 = new char[size];
    char* str2 = new char[size];

    cout<<"Enter the first string: \n";
    for(int i = 0; i<size; i++)
    {
        cin>>str1[i];
    }

    cout<<"Enter the second string: \n";
    for(int i = 0; i<size; i++)
    {
        cin>>str2[i];
    }

    if(checkrev(str1, str2, size))
        cout<<"Both the strings are reverse of each other\n";
    else
        cout<<"Strings are not reverse \n";
        
    delete[] str1;
    str1 = NULL;
    delete[] str2;
    str2 = NULL;

return 0;    
}
bool checkrev(char* str1, char* str2, int s)
{
    int check = 0;
    for(int i=0; i<s; i++)
    {
        if( str1[i] == str2[s-1-i] )
            check++;
    }

    if(check == s)
        return true;
    else
        return false;
}
