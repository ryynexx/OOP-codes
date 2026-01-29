#include <iostream>
using namespace std;
class car
{
    private:
        int currentspeed;
        static int maxspeed;
    public:
        void setspeed(int s)
        {
            currentspeed = s;

            if(currentspeed > maxspeed)
            {
                maxspeed = currentspeed;
            }
        }
        int getmaxspeed()
        {
            return maxspeed;
        }
};
int car::maxspeed = 0;
int main()
{
    car c1, c2 ,c3 ,c4;

    c1.setspeed(20);
    c2.setspeed(30);

    cout<<c1.getmaxspeed()<<"\n";

    c3.setspeed(10);
    cout<<c1.getmaxspeed()<<"\n";
    c4.setspeed(70);

    cout<<c2.getmaxspeed()<<"\n";

return 0;
}