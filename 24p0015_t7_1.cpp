#include <iostream>
using namespace std;
class logger 
{
  private:
    static string logs[10]; // Static array for storing logs
    static int count;       // Static counter for tracking logs

  public:
    logger() {}
    ~logger() {}

    void log(string msg) 
    {
        if (count < 10) 
        {   // Ensure we don't exceed array bounds
            logs[count] = msg;
            count++;
        } 
        else 
        {
            cout << "No more space.\n";
        }
    }
    void printlogs() 
    {
        for (int i = 0; i < count; i++) 
        {
            cout << logs[i] << endl;
        }
    }
};

string logger::logs[10]; 
int logger::count = 0;

int main() 
{
    logger l1, l2,l3; // Creating logger objects

    string msg;
    
    cout << "Enter Log message: ";
    getline(cin, msg);
    l1.log(msg); // Log first message

    cout << "Enter Log message: ";
    getline(cin, msg);
    l2.log(msg); // Log second message

    l3.log("You are using logger class.");

    l1.printlogs(); // Print logs

    return 0;
}
