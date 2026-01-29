#include <iostream>
using namespace std;
int** transpose(int** m, int r, int c);
int main()
{
  int row, col;
  cout<<"Enter the number of rows and columns of the matrix : \n";
  cin >> row >> col;
  
  int** matrix = new int*[row];
  int** matrix_t;
  for(int i=0; i<row; i++)
  {
    matrix[i] = new int[col];
  }
  
  cout<<"Enter the elements of array : \n";
  for(int i =0; i<row; i++)
  {
    for(int j=0; j<col; j++)
    {
      cin>> matrix[i][j];
    }
  }
  
  matrix_t = transpose(matrix, row, col);
  
  cout<<"Transpose of array : \n";
  for(int i =0; i<col; i++)
  {
    for(int j=0; j<row; j++)
    {
      cout<<matrix_t[i][j]<<" ";
    }
    cout<<"\n";
  }
  
  for(int i=0; i<row; i++)
  {
    delete[] matrix[i];
    matrix[i] = NULL;
  }
  for(int i=0; i<col; i++)
  {
    delete[] matrix_t[i];
    matrix_t[i] = NULL;
  }
  
  delete[] matrix;
  delete[] matrix_t;
  matrix = NULL;
  matrix_t = NULL;
  
  return 0;
}
int** transpose(int** m, int r, int c)
{ 
   int** m_t = new int*[c];
   
   for(int i=0; i<c; i++)
  {
    m_t[i] = new int[r];
  }
   for(int i = 0; i<r; i++)
   {
     for(int j=0; j<c; j++)
     {
       m_t[j][i] = m[i][j]; 
     }   
   }
   
   return m_t;
}
