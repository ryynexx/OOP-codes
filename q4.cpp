#include <iostream>
using namespace std;
int* addmatrix(int* mat1, int* mat2, int r, int c);
int main()
{
    int row, col;
    cout<<"Enter number of rows and columns of matrices : \n";
    cin>> row<< col;
    int* mat1 = new int[row*col];
    int* mat2 = new int[row*col];

    cout<<"Enter 1st matrix elements \n";
    for(int i=0; i<row; i++)
    {
        for(int j=0;j<col; j++)
        {
            cin>> mat1[i*col+j];
        }
    }

    cout<<"Enter 2nd matrix elements \n";
    for(int i=0; i<row; i++)
    {
        for(int j=0;j<col; j++)
        {
            cin>> mat2[i*col+j];
        }
    }

    int* mat3= addmatrix(mat1, mat2, row, col);

    cout<<"3rd matrix that is addition of two matrices\n";
    for(int i=0; i<row; i++)
    {
        for(int j=0;j<col; j++)
        {
            cin>> mat3[i*col+j];
        }
    }

    delete[] mat1, mat2, mat3;
    mat1=NULL;
    mat2=NULL;
    mat3=NULL;

  return 0;  
}
int* addmatrix(int* mat1, int* mat2, int r, int c)