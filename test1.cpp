#include <iostream>
using namespace std;
class Bankaccount
{
  private:
     int acc_no;
     double balance;
  public:
     Bankaccount()
     {
       acc_no = 01;
       balance = 0;
     }
  void display()
  {
   cout<<acc_no<<"\n";
   cout<<balance<<"\n";
  }
  
};
int main()
{
  Bankaccount Accounts[3];
  
  for(int i =0; i<3; i++)
  { cout<<"account "<<i<<"\n";
    Accounts[i].display();
  }
 return 0;
}

