#include <iostream>
using namespace std;
class Person
{   
    protected:
        string name;
        string address;
    public:
        Person(string n, string adr)
        {
            name = n;
            address = adr;
        }
        void set_name(string n)
        {
            name = n;
        }
        void set_address(string adr)
        {
            address = adr;
        }
        string get_name()
        {
            return name;
        }
        string get_address()
        {
            return address;
        }
};

class Employee : public Person
{
    protected:
        int emp_num;
        int hour_worked;
    public:
    Employee(string n, string adr, int empN, int hrs) : Person(n, adr), emp_num(empN), hour_worked(hrs) {}
        void set_emp_num(int empN)
        {
            emp_num= empN;
        }
        void set_hour_worked(int hrs)
        {
            hour_worked = hrs;
        }
        int get_emp_num()
        {
            return emp_num;
        }
        int get_hour_worked()
        {
            return hour_worked;
        }
};
class ProductionWorker : public Employee
{
    protected:
        int shift;
        double hr_payrate;
        double salary;
    public:
    ProductionWorker(string n, string adr, int empN, int hrs, int shf, double hpr) : Employee(n, adr, empN, hrs), shift(shf), hr_payrate(hpr), salary(0.0) {}
    void set_shift(int shf)
        {
            shift = shf;
        }
        void set_hr_payrate(double hpr)
        {
            hr_payrate = hpr;
        }
        void set_salary(double sal)
        {
            salary = sal;
        }
        int get_shift()
        {
            return shift;
        }
        double get_hr_payrate()
        {
            return hr_payrate;
        }
        double get_salary()
        {
            return salary;
        }
        void CalculateSalary()
        {
            set_salary(hr_payrate*hour_worked);
        }
        void Print_details()
        {
            cout<<"Name : "<<name<<"\n";
            cout<<"Address : "<<address<<"\n";
            cout<<"Employee No. "<<emp_num<<"\n";
            cout<<"Hours worked : "<<hour_worked<<"\n";
            if(shift == 1)
                cout<<"Shift : Day\n";
            else
                cout<<"Shift : Night\n";
            cout<<"Hourly Pay Rate : "<<hr_payrate<<"\n";
            cout<<"Salary : $"<<salary<<"\n";
        }
};
int main()
{
    ProductionWorker emp1( "Alex" , "Las Angelas street 30",100, 12, 1, 40 );
    emp1.CalculateSalary();
    emp1.Print_details();
return 0;
}