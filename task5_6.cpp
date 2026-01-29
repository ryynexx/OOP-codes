#include <iostream>
using namespace std;
struct address
{
    string city;
    int zip;
};
struct company
{
   string name;
   float revenue;
   address add;
};
int main()
{
    company companies[3];

    companies[0].name = "Dalda";
    companies[0].revenue = 340000;
    companies[0].add.city = "Karachi";
    companies[0].add.zip = 5405;

    companies[1].name = "Nestle";
    companies[1].revenue = 900000;
    companies[1].add.city = "Lahore";
    companies[1].add.zip = 2405;

    companies[2].name = "National";
    companies[2].revenue = 780000;
    companies[2].add.city = "Islamabad";
    companies[2].add.zip = 7809;

    for(int i=0; i<3; i++)
    {   
        cout<<"\nCompany : "<<(i+1)<<"\n";
        cout<<"\nName: "<<companies[i].name<<"\n";
        cout<<"Ravenue: "<<companies[i].revenue<<"\n";
        cout<<"City: "<<companies[i].add.city<<"\n";
        cout<<"Zip: "<<companies[i].add.zip<<"\n";
    }
return 0;
}