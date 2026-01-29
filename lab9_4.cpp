#include <iostream>
using namespace std;
class Employee 
{
    public:
    string name;
    int id;

    Employee()
    {
        name = "";
        id= 0;
    }

    Employee(string name, int id) 
    {
        this->name = name;
        this->id = id;
    }

    void display() 
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};
class Department 
{
    private:
    string d_Name;
    Employee* employees;
    int size;
    int count;

    public:
    Department(string name, int s) 
    {
        d_Name = name;
        this->size = s;
        count = 0;
        employees = new Employee[size];
    }

    ~Department() 
    {
        delete[] employees;
    }

    void addEmployee( Employee& e) 
    {
        if (count < size) 
        {
            employees[count++] = e;
            cout << "Employee added.\n";
        } 
        else 
        {
            cout << "Department is full!\n";
        }
    }

    void removeEmployee(int id)
     {
        bool found = false;
        for (int i = 0; i < count; ++i) 
        {
            if (employees[i].id == id) 
            {
                for (int j = i; j < count - 1; ++j) 
                {
                    employees[j] = employees[j + 1];
                }
                count--;
                found = true;
                cout << "Employee removed.\n";
                break;
            }
        }
        if (!found) 
        {
            cout << "Employee not found.\n";
        }
    }

    void displayEmployees() 
    {
        cout << "Department: " << d_Name << endl;
        for (int i = 0; i < count; ++i) 
        {
            employees[i].display();
        }
    }
};

int main() 
{
    Department d("Software", 5);

    Employee e1("Ayesha", 98);
    Employee e2("Ahmad", 65);
    Employee e3("Zaid", 43);

    d.addEmployee(e1);
    d.addEmployee(e2);
    d.addEmployee(e3);

    cout << "\nAll Employees:\n";
    d.displayEmployees();

    d.removeEmployee(65);

    cout << "\nAfter Removal:\n";
    d.displayEmployees();

return 0;
}
