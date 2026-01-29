#include <iostream>
using namespace std;
struct employee
{
   string name;
   int id;
   float salary;
};
int main()
{
    employee e1;
    employee* ptr = &e1;

    cout<<"Enter employee name: ";
    cin >> ptr->name;
    cout<<"Enter employee id: ";
    cin>>ptr->id;
    cout<<"Enter employee salary: ";
    cin>> ptr->salary;

    cout<<"\nEmplyee 1:\n";
    cout<<"ID: "<<(*ptr).id<<"\n";
    cout<<"Name: "<<(*ptr).name<<"\n";
    cout<<"Salary: "<<(*ptr).salary<<"\n";
return 0;

}