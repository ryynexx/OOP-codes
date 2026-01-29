#include <iostream>
using namespace std;
class Address
{

    public:
    string city;
    string town;
    string street;
    string house;
    
    Address(string c, string t, string s, string h)
    {
        city = c;
        town = t;
        street = s;
        house = h;
    }
};
class student
{
    private:
    string name;
    int id;
    Address* add;
    public:
    student(string n, int id,Address* a)
    {
        name = n;
        this->id = id;
        add = a;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Address : "<<add->city<<" "<<add->town<<" "<<add->street<<" "<<add->house<<"."<<endl;
    }
};
int main()
{
    Address add1("Peshawar","University town","street 3","house 9");
    student s1("Ahmad",101,&add1);
    s1.display();
return 0;
}