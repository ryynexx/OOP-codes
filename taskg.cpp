#include <iostream>
using namespace std;
int main()
{
   int row1,col1;
   int row2, col2;
   
   cout<<"Enter the number of rows and columns of matrix A : \n";
   cin >> row1 >> col1;
   
   cout<<"Enter the number of rows and columns of matrix B : \n";
   cin >> row2 >> col2;
   
   if(col1 == row2)
    {
      int** mat_a= new int*[row1];
    
      for(int i=0; i<row1; i++)
      {
        mat_a[i] = new int[col1];
      }
      
      cout<<"Enter first matrix : \n";
      for(int i = 0; i<row1; i++)
      {      
        for(int j= 0; j<col1; j++ )
        {
          cin >> mat_a[i][j];
        }
      }
      
      int** mat_b= new int*[row2];
    
      for(int i=0; i<row2; i++)
      {
        mat_b[i] = new int[col2];
      }
      
      cout<<"Enter second matrix : \n";
      for(int i = 0; i<row2; i++)
      {      
        for(int j= 0; j<col2; j++ )
        {
          cin >> mat_b[i][j];
        }
      }
      
      int** mat_c = new int*[row1];
      
       for(int i=0; i<row2; i++)
      {
        mat_c[i] = new int[col2];
      }
      //multiplying matrices
       for (int i = 0; i < row1; i++)
       {
        for (int j = 0; j < col2; j++) 
        {
            for (int k = 0; k < col1; k++) 
            {
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }
    
    cout<<"Resultant Matrix: \n";
    for(int i = 0; i<row1; i++)
      {      
        for(int j= 0; j<col2; j++ )
        {
          cout<< mat_c[i][j]<<" ";
        }
        cout<<"\n";
      }
  
  
  for(int i=0; i<row1; i++)
  {
    delete[] mat_a[i];
    mat_a[i] = NULL;
    delete[] mat_c[i];
    mat_c[i] = NULL;
  }
  
  for(int j=0; j<row2;j++)
  {
    delete[] mat_b[j];
    mat_b[j] = NULL;
  }
  
  delete[] mat_a;
  delete[] mat_b;
  delete[] mat_c;
  mat_a = NULL;
  mat_b = NULL;
  mat_c = NULL;
}
 else
    {
      cout<< "Matrices cannot be multiplied. Number of columns in A must be equal to number of rows in B.\n";
      return 0;
    }   
    
    return 0;
}


