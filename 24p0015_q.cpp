#include <iostream>
using namespace std;
class flight
{
    protected:
        int flight_no;
        string dep_ap;
        string arr_ap;
        string dep_time;
        string arr_time;
        string airline_info;
};
class standard : public flight
{

};
class luxury : public flight
{

};
class premium : public flight
{

};
