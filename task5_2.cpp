#include <iostream>
using namespace std;
struct Book
{
    string title;
    string author;
    float price;

    void display_p500();
};
void Book :: display_p500()
{
    if(price > 500)
    { 
        cout<<"\nTitle: "<<title;
        cout<<"\nAuthor: "<<author;
        cout<<"\nPrice: "<<price<<"\n";
    }
}
int main()
{
    Book lib[5] = {
                   {"Art of Being Alone","Renuka Gavrani",2
                    00},
                   {"Pir-e-Kamil","Umera Ahmad",1000},
                   {"Forty Rules of Love","Elif Shafaq",800},
                   {"Alchemist","Paulo Coelho",300},
                   {"Kite Runner","Khaled Hosseni",500}
                  };

    for(int i=0; i<5; i++)
    {
        lib[i].display_p500();
    }               
    return 0;

}