#include <iostream>
using namespace std;
class Engine
{
    public:
        void destroyed()
        {
            cout<<"Engine Destroyed!!\n";
        }
        
};
class Car
{
   private: 
        Engine engine;
    public:
       void c_destroy()
       {
        cout<<"Car Destroyed!!\n";
        engine.destroyed();
       }
};
int main()
{
    Car car1;

    car1.c_destroy();
return 0;
}
