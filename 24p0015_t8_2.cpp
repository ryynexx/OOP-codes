#include <iostream>
using namespace std;
class Device
{   
    protected:
        string deviceName;
        bool powerStatus;
        string location;
    public:
        Device(string devN, string l) : deviceName(devN), location(l), powerStatus(false) {}
        void turnOn()
        {
            powerStatus = true;
        }
        void turnOff()
        {
            powerStatus = false;
        }
        void showStatus()
        {
            if(powerStatus)
                cout<<"Current Status : ON \n";
            else
                cout<<"Current Status : OFF \n";
        }
};
class SmartLight : public Device
{
    protected:
        int brightness;
        string color;
    public:
        SmartLight(string devN, string l, int level, string c): Device(devN, l), brightness(level), color(c) {}
    
        void adjustBrightness(int level)
        {
            brightness = level;
        }
        void changeColor(string newColor)
        {
            color = newColor;
        }

};
class SmartThermostat : public Device
{
    protected:
        float temperature;
        string mode;
    public:
        SmartThermostat(string devN, string l, float temp, string m): Device(devN, l), temperature(temp), mode(m) {}
    
        void setTemperature(float temp)
        {
            temperature = temp;
        }
        void switchMode(string newMode)
        {
            mode = newMode;
        }
};
class SmartSecurityCamera : public Device
{
    protected:
        string resolution;
        bool recordingStatus;
    public:
        SmartSecurityCamera(string devN, string l, string res): Device(devN, l), resolution(res), recordingStatus(false) {}
    
        void startRecording()
        {
            recordingStatus = true;
        }
        void stopRecording()
        {
            recordingStatus = false;
        }
        void viewFeed() 
        {
            cout << "Live feed from " << deviceName << " in " << resolution << " resolution." << endl;
            cout<<"Location : "<<location<<"\n";
        }
};
int main()
{   
    cout<<"\nSmart Light\n";
    SmartLight livingroomLight("Livingroom Light", "living room", 50, "Blue");
    livingroomLight.turnOn();
    livingroomLight.showStatus();

    cout<<"\nSmart Thermostat\n";
    SmartThermostat homeThermostat("Home Thermostat", "Bedroom", 16, "Heat");
    homeThermostat.turnOn();
    homeThermostat.showStatus();
    
    cout<<"\nSmart Security Camera\n";
    SmartSecurityCamera entranceCam("Entrance Camera", "Front Door", "4K");
    entranceCam.turnOn();
    entranceCam.startRecording();
    entranceCam.viewFeed();
    entranceCam.showStatus();
    
    return 0;
}
