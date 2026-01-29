#include <iostream>
using namespace std;
class Employee//abstract class
{
    protected:
        string emp_name;
        int emp_id;
        double salary;
    public:
        Employee() {}
        ~Employee() {}
        Employee(string name, int id, double sal) : emp_name(name), emp_id(id), salary(sal) {};
        virtual double calculate_bonus() = 0;//pure virtual function
        string getname()
        {
            return emp_name;
        }
        int getid()
        {
            return emp_id;
        }
};
class Manager : public Employee
{
    private:
        long int contact;
        float appraisal;
    public: 
        Manager() {}
        ~Manager() {}
        Manager(string name, int id, double sal,long int cont,float ap) : Employee(name,id,sal), contact(cont), appraisal(ap) {};
        double calculate_bonus()//calculating manager balance
        {
            return salary*0.20*appraisal;
        }
};
class Engineer : public Employee
{
    protected:
        long int contact;
        float appraisal;
    public:
        Engineer() {}
        ~Engineer() {}
        Engineer(string name, int id, double sal, long int cont,float ap) : Employee(name,id,sal), contact(cont), appraisal(ap) {};
        double calculate_bonus()//ca;culating engineer balance
        {
            return salary*0.35*appraisal;
        }

};
class Department
{
    private:
        string dep_name;
        Engineer* engineers;//aggregation
        int num_eng;
    public:
        Department() {}
        ~Department() {}
        Department(string name, Engineer* engnrs, int num) : dep_name(name), engineers(engnrs), num_eng(num) {};

        void display_dep()
        {
            cout<<"Department : "<<dep_name<<"\n";
            cout<<"Engineers : \n";
            for(int i =0; i<num_eng; i++)
            {
                cout<<"\n------"<<i+1<<"-------\n";
                cout<<"Engineer Name : "<<engineers[i].getname()<<endl;
                cout<<"ID : "<<engineers[i].getid()<<endl;
            }
        }
};
class Engine
{
    private:
        string eng_power;
    public:
        Engine(string pow = "1000cc") 
        {
            eng_power = pow;
            cout<<"Engine Started.\n";
        }
        ~Engine() 
        {
            cout<<"Engine Destroyed.\n";
        }
        string getpow()
        {
            return eng_power;
        }
};
class Car : public Engineer
{
    private:
        int model;
        string car_name;
        Engine engine;//composition
    public:
        Car() {}
        Car(string name, int id, double sal,long long int cont,float ap, int mod = 2023,string c_name = "corolla")
        {
            Engineer(name, id , sal,cont, ap);
            model = mod;
            car_name = name;
            cout<<"Car Started.\n";
        }
        ~Car()
        {
            cout<<"Car Destroyed.\n";
        }
        void display_car()
        {
            cout<<"Engineer : "<<emp_name<<endl;
            cout<<"Car : "<<car_name<<endl;
            cout<<"Model : "<<model<<endl;
            cout<<"Engine : "<<engine.getpow()<<endl;
        }
};
int main()
{
    Manager man1("Ahmad", 010, 80000, 6879875443, 1.2);
    Engineer eng1("Ali", 102, 120000, 7898372531, 2.4);
    Engineer eng2("Zahid", 304,200000, 3425734535, 2.0);

    cout<<"Bonus Of Manager : "<<man1.calculate_bonus()<<"\n";
    cout<<"Bonus of Engineer : "<<eng1.calculate_bonus()<<"\n";
    
    Engineer engineers[] = {eng1,eng2};
    Department dep1("AI",engineers,2);
    dep1.display_dep();
    Car car1("Ali", 102, 120000, 7898372531, 2.4);

return 0;

}