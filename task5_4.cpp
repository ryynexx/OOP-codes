#include <iostream>
using namespace std;
struct student
{
    string name;
    int rollno;
    float marks;
};
int main()
{
    int n;

    cout<<"Enter the number of students: ";
    cin>>n;

    student* record = new student[n];
    
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter details of student "<<(i+1)<<"\n";
        cout<<"Name : ";
        cin>>record[i].name;
        cout<<"Roll No. ";
        cin>>record[i].rollno;
        cout<<"Marks : ";
        cin>>record[i].marks;
    }
    cout<<"Record of students:\n";
    for(int i =0; i<n; i++)
    {
        cout<<"\nStudent "<<(i+1)<<"\n";
        cout<<"\nName : "<<record[i].name;
        cout<<"\nRoll No. "<<record[i].rollno;
        cout<<"\nMarks : "<<record[i].marks<<"\n";
    }
}