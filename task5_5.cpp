#include <iostream>
using namespace std;
struct Book
{
    string title;
    string author;
    float price;
};
void input(Book* lib, int n)
{
    for(int i = 0; i<n; i++)
    {   
        cout<<"\nEnter details of Book: "<<i+1<<"\n";
        cout<<"\nTitle: ";
        cin.ignore();ssssss
        getline(cin, lib[i].title);
        cout<<"Author: ";
        getline(cin, lib[i].author);
        cout<<"Price: ";
        cin>>lib[i].price;
    }
    
}
void display(Book* lib, int n)
{   
    for(int i=0; i<n; i++)
    {
        cout<<"\nBook: "<<i+1<<"\n";
        cout<<"\nTitle: "<<lib[i].title;
        cout<<"\nAuthor: "<<lib[i].author;
        cout<<"\nPrice: "<<lib[i].price<<"\n";
    }
}
void most_exp(Book* lib,int n)
{   
    float max;
    for(int i =0 ; i<n-1; i++)
    {
        if(lib[i].price > lib[i+1].price)
            max = lib[i].price;
        else
            max = lib[i+1].price;
    }
    for(int i =0 ; i<n; i++)
    {
        if(max == lib[i].price)
        {
            cout<<"\nMost expensive book: \n";
            cout<<"\nTitle: "<<lib[i].title;
            cout<<"\nAuthor: "<<lib[i].author;
            cout<<"\nPrice: "<<lib[i].price<<"\n";
        }

    }

}
int main()
{
    int n;
    cout<<"Enter number of Books: ";
    cin >> n;
    Book* lib= new Book[n];

    input(lib, n);
    display(lib, n);
    most_exp(lib, n);
return 0;
}