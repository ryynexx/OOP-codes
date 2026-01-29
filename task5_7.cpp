#include <iostream>
using namespace std;
struct car 
{ 
    string brand;
    int year;
    float price;  
};
void updatePrice(car *c,float discount )
{
    float dis_amount = (c->price * discount)/100;
    c->price -= dis_amount;
}
int main()
{   
    car c1;
    int discount;

    cout<<"Enter car details: \n";
    cout<<"Brand: ";
    cin>>c1.brand;
    cout<<"Year: ";
    cin>>c1.year;
    cout<<"Price: ";
    cin>>c1.price;

    cout<<"Enter discount amount: ";
    cin >> discount;

    updatePrice(&c1,discount);

    cout<<"After price updation: \n";
    cout<<"Price: "<<c1.price<<"\n";
return 0;


}