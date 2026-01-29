#include <iostream>
using namespace std;
class CoffeeOrder
{
    protected:
        int size;
        int price;
    public:
        CoffeeOrder(int s, int p) : size(s) , price(p) {}
        void processOrder()
        {
            cout<<"Total Cost : $"<<(size*price)<<"\n";
        }
};
class CustomOrder : public CoffeeOrder
{
    public:
        CustomOrder(int s, int p) : CoffeeOrder(s,p) {}
        void processOrder()
        {
            cout<<"\n~~~Welcome to Coffee Shop!!~~~\n";
            CoffeeOrder::processOrder();
        }   
};
int main()
{
    int s,p ;

    cout<<"Enter the size and price of your coffee order.\n";
    cin>>s>>p;

    CoffeeOrder order1(s,p);
    order1.processOrder();

    cout<<"Enter the size and price of your coffee order.\n";
    cin>>s>>p;

    CustomOrder order2(s,p);
    order2.processOrder();
return 0;
}