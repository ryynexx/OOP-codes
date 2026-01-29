#include <iostream>
using namespace std;
class Device
{
    protected:
        string deviceID;
        string status;
    public:
        Device() {}
        Device(string id, string stat)
        {
            deviceID = id;
            status = stat;
        }
        virtual void displayStatus()=0;
        

};
class Sensor :  public Device
{
    protected:
        double value;
    public:
        Sensor() 
        {
            value = 25;
        }
        Sensor(string id, string status, double val) : Device(id, status), value (val){};
        
        void displayStatus()
        {
            cout<<"Status of Sensor : "<<status<<endl;
        }

};
class Controller :  public Device
{
    protected:
        bool active;
    public:
        Controller()
        {
            active = true;
        }
        Controller(string id, string status,bool act = true) : Device(id, status) { };
        void turnoff()
        {
            active = false;
        }
        void displayStatus()
        {
            cout<<"Status of Controller : "<<status<<endl;
        }
};
class SmartDevice : virtual public Controller, virtual public Sensor
{

    public:
        void diplayStatus()
        {
            Controller::displayStatus();
        }
};
