#include <iostream>
using namespace std;
class Book
{
    private: 
        string books[6];
    public:
        Book()
        {
            string list[6] = {"Alif","Mashaf","Forty Rules of Love","Book Thief","Kite Runner","Eclipse"};
             for (int i = 0; i < 6; ++i) 
             {
              books[i] = list[i];
             }
        }
        void display()
        {
            cout<<"\nBooks list : \n";
            for(int i=0;i<6;i++)
            {
                cout<<books[i]<<endl;
            }
        }
        void destroy()
        {
            cout<<"Books are destroyed\n";
        }
};
class Library
{
    private:
        Book mybooks;
    public:
        Library()
        {
            cout<<"Library is Open\n";
            mybooks.display();
        }
        void close()
        {
            cout<<"\nLibrary is destroyed\n";
            mybooks.destroy();
        }
};
int main()
{
    Library lib;
    
    lib.close();

return 0;
}
