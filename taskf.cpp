#include <iostream>
using namespace std;
int main()
{
  int row=50,col=100;
  
  int** theater = new int*[row];
  for(int i =0; i <row; i++)
  {
    theater[i] = new int[col];
  }
  
  for(int i = 0 ; i < row ; i++)
  {
    for(int j=0; j<col; j++)
    {
      theater[i][j]= 0;
    }
  }
  int r, c;
  int count=0;
  while(1)
  {
   cout<<"Enter row and seat number to reserve (0 0 to stop): \n ";
   cin>>r>>c;
   if(r == 0 && c == 0)
   {
     break;
   }
   if(r > 49 || c >99)
   {
     cout<<"invalid seat number , please try again.\n";
   }
   else if(theater[r][c] == 0)
   {
    cout<<"Seat reserved , successfully.\n";
    theater[r][c] = 1;
    count++;
   }
   else
   {
     cout<<"Seat already reserved , please try again.\n";
   }
  }
  
  cout<<"Total number of seats reserved : "<<count<<"\n";
  
  for(int i =0; i <row; i++)
  {
    delete[] theater[i];
    theater[i] = NULL;
  }
  delete[] theater;
  theater = NULL;
 return 0;
}
