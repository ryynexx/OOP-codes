#include <iostream>
using namespace std;

class TimeClass // Renamed to avoid conflicts
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    TimeClass() // Default constructor
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    TimeClass(int h, int m, int s) // Parameterized constructor
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void display()
    {
        if (hours < 10)
            cout << "0" << hours << " : ";
        else
            cout << hours << " : ";

        if (minutes < 10)
            cout << "0" << minutes << " : ";
        else
            cout << minutes << " : ";

        if (seconds < 10)
            cout << "0" << seconds << endl;
        else
            cout << seconds << endl;
    }
    void Addtime(TimeClass t1, TimeClass t2)
    {   
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + (seconds/60);
        hours = t1.hours + t2.hours+ (minutes/60);
        seconds %=60;
        minutes %= 60;
        hours %= 24;
       
    }
};

int main()
{
    TimeClass t1(3,20,47);            // Default constructor
    TimeClass t2(2, 50, 6);  // Correct object initialization
    TimeClass t3;

    t3.Addtime(t1,t2);
    t1.display();
    t2.display();
    t3.display();

    return 0;
}
