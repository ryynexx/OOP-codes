#include <iostream>
using namespace std;
struct rectangle
{
    float length;
    float width;

    float area(rectangle r);
};
float rectangle :: area(rectangle r)
{
    return length * width;
}
int main()
{
    rectangle r1;

    cout<<"Enter the length and width of the rectangle: \n";
    cin>> r1.length >> r1.width;

    cout<<"Area of rectangle is : \n";
    cout<< r1.area(r1)<<endl;
return 0;
}