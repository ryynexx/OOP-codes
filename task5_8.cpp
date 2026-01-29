#include <iostream>
using namespace std;
struct Doctor
{
    string name;
    string specialization;
};
struct Hospital
{
    string h_name;
    Doctor doc[3];
};
void display(Hospital* h,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"\nHospital : "<<i+1<<"\n";
        cout<<"Hospital : "<<h[i].h_name<<"\n";
        for(int j=0; j<3; j++)
        { 
            cout<<"\nDoctor : "<<j+1<<"\n";
            cout<<"Doctor name : "<<h[i].doc[j].name;
            cout<<"\nDoctor specialization : "<<h[i].doc[j].specialization;
        }
        cout<<"\n";
        
    }

}
int main()
{   
    int n;
    cout<<"Enter number of hospitals: ";
    cin>> n;
    Hospital* hospitals = new Hospital[n];

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter details of Hospital : "<<i+1<<"\n";
        cout<<"Hospital : ";
        cin.ignore();
        getline(cin, hospitals[i].h_name);
        for(int j=0; j<3; j++)
        { 
            cout<<"\nEnter details of Doctor : "<<j+1<<"\n";
            cout<<"Doctor name : ";
            getline(cin, hospitals[i].doc[j].name);
            cout<<"Doctor specialization : ";
            getline(cin, hospitals[i].doc[j].specialization);
        }
        cout<<"\n";
        
    }

    display(hospitals,n);
return 0;
}
