#include <iostream>
using namespace std;

// Student Structure
struct Student 
{
    string s_name;
    string reg_no;
    float gpa;
};

// Professor Structure
struct Professor 
{
    string p_name;
    int emp_id;
    string subject;
};

// Course Structure
struct Course 
{
    string c_name;
    int num_stud;
    Student* students;
    Professor prof;
};

// University Structure
struct University 
{
    string uni_name;
    string location;
    Course* courses;
    int num_courses;
};

// Function to add initial courses
void addcourses(University* uni, int n) 
{
    uni->num_courses = n;
    uni->courses = new Course[n];
    cout << "Enter Course details: \n";
    cin.ignore();
    for (int i = 0; i < n; i++) 
    {
        cout << "\nCourse Name: ";
        getline(cin, uni->courses[i].c_name);
        cout << "Number of Students: ";
        cin >> uni->courses[i].num_stud;
        cin.ignore();
        uni->courses[i].students = new Student[uni->courses[i].num_stud];
        cout << "Enter Student Details:\n";
        for (int j = 0; j < uni->courses[i].num_stud; j++) 
        {
            cout << "\nStudent Name: ";
            getline(cin, uni->courses[i].students[j].s_name);
            cout << "Registration No: ";
            getline(cin, uni->courses[i].students[j].reg_no);
            cout << "Grade (GPA): ";
            cin >> uni->courses[i].students[j].gpa;
            cin.ignore();
        }
        cout << "Enter Professor details:\n";
        cout << "Professor Name: ";
        getline(cin, uni->courses[i].prof.p_name);
        cout << "Employee ID: ";
        cin >> uni->courses[i].prof.emp_id;
        cin.ignore();
        cout << "Subject Name: ";
        getline(cin, uni->courses[i].prof.subject);
    }
}

// Function to add a new course
void newcourse(University* uni) 
{
    uni->num_courses++;
    Course* newcourse = new Course[uni->num_courses];
    for (int i = 0; i < uni->num_courses - 1; i++) 
    {
        newcourse[i] = uni->courses[i];
    }
    cout << "Enter Course details:\n";
    cin.ignore();
    cout << "\nCourse Name: ";
    getline(cin, newcourse[uni->num_courses - 1].c_name);
    cout << "Number of Students: ";
    cin >> newcourse[uni->num_courses - 1].num_stud;
    cin.ignore();
    newcourse[uni->num_courses - 1].students = new Student[newcourse[uni->num_courses - 1].num_stud];
    cout << "Enter Professor details:\n";
    cout << "Professor Name: ";
    getline(cin, newcourse[uni->num_courses - 1].prof.p_name);
    cout << "Employee ID: ";
    cin >> newcourse[uni->num_courses - 1].prof.emp_id;
    cin.ignore();
    cout << "Subject Name: ";
    getline(cin, newcourse[uni->num_courses - 1].prof.subject);
    delete[] uni->courses;
    uni->courses = newcourse;
}

// Function to enroll a new student in a course
void addstud(University* uni) 
{
    int i;
    cout << "Enter Course number: ";
    cin >> i;
    i--;
    if (i < 0 || i >= uni->num_courses) 
    {
        cout << "Invalid course number.\n";
        return;
    }
    uni->courses[i].num_stud++;
    Student* newstudents = new Student[uni->courses[i].num_stud];
    for (int j = 0; j < uni->courses[i].num_stud - 1; j++) 
    {
        newstudents[j] = uni->courses[i].students[j];
    }
    cout << "Enter new student details:\n";
    cin.ignore();
    cout << "Student Name: ";
    getline(cin, newstudents[uni->courses[i].num_stud - 1].s_name);
    cout << "Registration No: ";
    getline(cin, newstudents[uni->courses[i].num_stud - 1].reg_no);
    cout << "Grade (GPA): ";
    cin >> newstudents[uni->courses[i].num_stud - 1].gpa;
    cin.ignore();
    delete[] uni->courses[i].students;
    uni->courses[i].students = newstudents;
}

// Function to display all courses and students
void display(University* uni) 
{
    cout << "\nUniversity: " << uni->uni_name << "\nLocation: " << uni->location << "\n";
    for (int i = 0; i < uni->num_courses; i++) 
    {
        cout << "\nCourse: " << uni->courses[i].c_name;
        cout << "\nProfessor: " << uni->courses[i].prof.p_name << " (" << uni->courses[i].prof.subject << ")\n";
        for (int j = 0; j < uni->courses[i].num_stud; j++) 
        {
            cout << "\nStudent: " << uni->courses[i].students[j].s_name << " (" << uni->courses[i].students[j].reg_no << ")\nGPA: " << uni->courses[i].students[j].gpa;
        }
    }
}

// Memory Cleanup Function
void freeMemory(University* uni) 
{
    for (int i = 0; i < uni->num_courses; i++) 
    {
        delete[] uni->courses[i].students;
    }
    delete[] uni->courses;
}

// Main Function
int main() 
{
    University uni;
    cout << "Enter University Name: ";
    getline(cin, uni.uni_name);
    cout << "Enter Location: ";
    getline(cin, uni.location);
    int n;
    cout << "Enter number of initial courses: ";
    cin >> n;
    addcourses(&uni, n);
    int choice;
    do 
    {
        cout << "\n1. Add New Course\n2. Enroll Student\n3. Display Data\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1: newcourse(&uni); break;
            case 2: addstud(&uni); break;
            case 3: display(&uni); break;
            case 4: freeMemory(&uni); cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    }
     while (choice != 4);
    return 0;
}
