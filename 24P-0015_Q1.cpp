#include <iostream>
using namespace std;
class Department
{
    private:
        string dep_name;
        Professor* professors;
        Student* students;
        int num_prof;
        int num_st;

    public:
        Department() {}
        Department(string d_name, Student* st,int n_st)
        {
            dep_name = d_name;
            students = st;
            num_st = n_st;
            professors = new Professor[5];
            num_prof = 0;
        } 
        ~Department() 
        {
            delete[] professors;
            professors = NULL;
        }
        void AddProf(Professor* prof)
        {
            if(num_prof<5)
            {
                professors[num_prof] = *(prof);
                num_prof++;
            }
            else
            {
                Professor* new_prof = new Professor[num_prof+1];
                for(int i = 0; i<num_prof; i++)
                {
                    new_prof[i] = professors[i];
                }
                new_prof[num_prof+1] = *(prof);
                delete[] professors;
                professors = new_prof;
                num_prof++;
            }
        }
        void UpdateStudents(Student* st)
        {
            students = st;
        }
        virtual void display()
        {
            for(int i = 0; i<num_prof; i++)
            {
                professors->display();
            }
        }

};
class Admin;
class Professor
{
    protected:
        string prof_name;
        string prof_id;
        double salary;
        string prof_type;
    public:
        Professor() {}
        Professor(string name, string id, double sal, string type)
        {
            prof_name = name;
            prof_id = id;
            salary = sal;
            prof_type = type;
        }
        virtual void ReportSalary() {}
        virtual void display()
        {
            cout<<"Professor Name : "<<prof_name<<endl;
            cout<<"Professor ID : "<<prof_id<<endl;
            cout<<"professor Type : "<<prof_type<<endl;
        }

        friend Admin;

};
class PermenentProfessor : public Professor
{
    private:
        string subject;
    public:
        PermenentProfessor(string n, string id, double sal, string sub) : Professor(n,id,sal,"Permenent"), subject(sub) {};
        void ReportSalary()
        {
            cout<<"Annual Salary : "<<salary<<endl;
        }  
        void display()
        {
            Professor :: display();
            cout<<"subject : "<<subject<<endl;
            ReportSalary();
        } 
};
class VisitingProfessor : public Professor
{
    private:
        string subject;
    public:
    VisitingProfessor(string n, string id, double sal,string sub) : Professor(n,id,sal,"Visiting") , subject(sub) {};
        void ReportSalary()
        {
            cout<<"Contract Salary : "<<salary<<endl;
        }
        void display()
        {
            Professor :: display();
            cout<<"subject : "<<subject<<endl;
            ReportSalary();
        } 
};
class Student
{
    private:
        string st_name;
        string st_id;
        double fee;
        int semester;
    public:
        Student() {}
        Student(string name, string id, double f, int sem)
        {
            st_name = name;
            st_id = id;
            fee = f;
            semester = sem;
        }
        ~Student() {}
        virtual void display()
        {
            cout<<"Student name : "<<st_name<<endl;
            cout<<"Student ID : "<<st_id<<endl;
            cout<<"Student Semester : "<<semester<<endl;
            cout<<"Student Fee : "<<fee<<endl;
        }
        void feePetition()
        {
            cout<<"student can not access professor salary.\n\n";
        }
};
class Admin
{
    public:
        void AccessSalary(Professor* p)
        {
            p->ReportSalary();
        }
};
int main()
{
    Student s1("Ali","24P-0015",200000, 2);
    Student s2("Ahmad", "24P-0016",1800000,3);
    Student* students = new Student[2];
    students[0] = s1;
    students[1] = s2;
    Department dep1("Computer Science",students, 2);

    VisitingProfessor prof1("Zaid","101",1000000,"Pf");
    PermenentProfessor prof2("Ayesha","201", 200000,"OOP");

    Professor* ptr1 = &prof1;
    Professor* ptr2 = &prof2;

    dep1.AddProf(ptr1);
    dep1.AddProf(ptr2);

    ptr1->display();
    ptr2->display();

    dep1.display();

    Admin ad1;
    ad1.AccessSalary(ptr1);

    s1.feePetition();

return 0;

}