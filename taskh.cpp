#include <iostream>
using namespace std;
struct Book
{
  string title;
  string author;
  int pages;
  float price;
};
int main()
{
  Book book1;
  
  cout<<"Enter details of the book.\n";
  cout<<"Title : ";
  cin>> book1.title;
  cout<<"Author: ";
  cin>> book1.author;
  cout<<"No of Pages : ";
  cin >> book1.pages;
  cout<< "Price : ";
  cin >> book1.price;
  
  cout<<"Title : "<<book1.title;
  cout<<"\nAuthor: "<<book1.author;
  cout<<"\nNo of Pages : "<<book1.pages;
  cout<< "\nPrice : "<<book1.price;
  
  return 0;
  
}
