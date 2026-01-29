#include <iostream>
#include <cmath>
using namespace std;
class PointB;
class PointA
{
    private:
        int x;
        int y;
    public:
        PointA()
        {
            x = 10;
            y = 12;
        }
        ~PointA(){}
       
    friend double calculateDistance(PointA, PointB );
};
class PointB
{
    private:
        int x;
        int y;
    public:
        PointB()
        {
            x =9 ;
            y = 5;
        }
        
    friend double calculateDistance(PointA,PointB);
};
double calculateDistance(PointA a, PointB b )
{
     return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}
int main()
{
    PointA a1;
    PointB b1;

    cout<<"Distace : "<<calculateDistance(a1,b1)<<endl;
return 0;
}