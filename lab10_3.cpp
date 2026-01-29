#include <iostream>
using namespace std;
class Width;
class Length
{
    private:
        float length;
    public:
        Length(float l)
        {
            length = l;
        }
       
    friend double calculateArea(Length, Width );
};
class Width
{
    private:
        float width;
    public:
        Width(float w)
        {
            width = w;
        }
        
    friend double calculateArea(Length,Width);
};
double calculateArea(Length l, Width w )
{
   return l.length*w.width;
}
int main()
{
    Length l1(3.4);
    Width w1(2.5);

    cout<<"Area : "<<calculateArea(l1,w1)<<endl;
return 0;
}