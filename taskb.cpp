#include <iostream>
using namespace std;
int main()
{ int row=5, col=5;
  char** str = new char*[row];
  for(int i=0; i<row; i++)
  { 
     str[i] = new char[col];
  }
	  
  char strinit[5][5] = { "Read", "Bear", "Hat", "Beat", " " };

    for (int i = 0; i < row; i++) 
    {
      for (int j = 0; j<col; j++)
      {
        str[i][j]=strinit[i][j];
      }
    }
    cout<<"Array before transforming: \n";  
    for (int i = 0; i < row; i++) 
    {
      for (int j = 0; j<col; j++)
      {
       cout<< str[i][j];
      }
      cout<<endl;
    } 
    
  
      char swap= str[0][0];
      str[0][0] = str[1][0];
      str[1][0] = swap;
	      
      swap= str[2][0];
      str[2][0] = str[3][0];
      str[3][0] = swap;
      
    cout<<"Array after transforming: \n";  
    for (int i = 0; i < row; i++) 
    {
      for (int j = 0; j<col; j++)
      {
       cout<< str[i][j];
      }
      cout<<endl;
    } 
    
      
    int count=0; 
    for (int i = 0; i < row; i++) 
    {
      for (int j = 0; j<col; j++)
      {
        if(str[i][j]!='\0')
        count++;
      }
    }
    
    cout<<"Total number of characters : "<<count<<"\n";
	     
    for(int i=0; i<row; i++)
    { 
      delete[]  str[i];
      str[i] = NULL;
    }
	  
  delete[]  str;
  str = NULL;
  
 return 0;
 }
