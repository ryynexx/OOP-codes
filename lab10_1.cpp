#include <iostream>
using namespace std;
class Balance;
class Bankaccount
{
    private:
        int acc_no;
    public:
        Bankaccount()
        {
            acc_no = 1124353907;
        }
        ~Bankaccount(){}
       
    friend void displayAll(Bankaccount, Balance );
};
class Balance
{
    private:
        double balance;
    public:
        Balance()
        {
            balance = 8000000;
        }
        
    friend void displayAll(Bankaccount,Balance);
};
void displayAll(Bankaccount b_acc, Balance bal )
{
    cout<<"Account Number: "<<b_acc.acc_no<<"\n";
    cout<<"Balance : "<<bal.balance<<"\n";
}
int main()
{
    Bankaccount b_acc;
    Balance bal;

    displayAll(b_acc, bal);
return 0;
}