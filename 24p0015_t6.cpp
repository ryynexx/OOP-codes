#include <iostream>
using namespace std;
class school
{
 private:
    string* name;
    int* rollno;
    float** marks;
    int students;
 public:
    school()
    { 
      students = 10;
      name = new string[students];
      rollno = new int[students];
      marks = new float*[students];
      for(int i = 0; i<students; i++)
      {
         marks[i] = new float[3];
      }
    }
    school(int n)
    { 
      students = n;
      name = new string[n];
      rollno = new int[n];
      marks = new float*[n];
      for(int i = 0; i<n; i++)
      {
         marks[i] = new float[3];
      }
    }

    ~school() 
    { 
      
      delete[] name;
      delete[] rollno;
      for (int i = 0; i < students; i++) 
      {
          delete[] marks[i];
      }
      delete[] marks;
    }
    void resize(int new_n)
    {
      if((new_n+students)<=(students*2))
      {
         int new_students = students +new_n;
         string* new_name = new string[new_students];
         int* new_rollno = new int[new_students];
         float** new_marks = new float*[new_students];
         for(int i = 0; i<new_students; i++)
         {
            new_marks[i] = new float[3];
         }
         for(int i=0; i<students; i++)
         {
            new_name[i] = name[i];
            new_rollno[i] = rollno[i];
            for(int k= 0; k<3; k++)
            {
               new_marks[i][k] = marks[i][k];
            }
         }
         students = new_students;
         delete[] name;
         delete[] rollno;
         for (int i = 0; i < students; i++) 
         {
            delete[] marks[i];
         }
         delete[] marks;

         name = new_name;
         rollno = new_rollno;
         marks = new_marks;
         for(int i = 0; i<new_students; i++)
         {
            marks[i] = new_marks[i]; 
         }
      }
      else
         cout<<"Can not add more than the double of the current number of students.\n";
     
   }
    void inputdata(int i)
    {
       cout<<"\nName : ";
       cin.ignore();
       getline(cin,name[i]);
       cout<<"Roll No. ";
       cin>>rollno[i];
       cout<<"Enter marks for three subjects: \n";
       for(int j=0; j<3; j++)
       {
            cin>>marks[i][j];
       }
    }
    void display()
    {
       cout<<"\nStudents Record : \n";
       for(int j =0; j<students; j++)
       {
         cout<<"\nName : "<<name[j]<<"\n";
         cout<<"Roll No. "<<rollno[j]<<"\n";
         cout<<"Marks for three subjects: \n";
         for(int k=0; k<3; k++)
         {
               cout<<marks[j][k]<<" ";
         }
         cout<<"\n";
       }
    }
    void average()
    { 
      float sum= 0;
      float avg = 0;
      for(int i= 0; i<students; i++)
      { 
         sum = 0;
         for(int j= 0; j<3; j++)
         {
            sum +=marks[i][j];
         }
         avg = sum/3;
         cout<<"Average of Student "<<(i+1)<<" "<<name[i]<<" : "<<avg<<"\n";
      }
    }
    void Topper()
    {
      float sum= 0;
      float sum2 = 0;
      int top = 0;
      for(int i= 0; i<students; i++)
      { 
         sum = 0;
         for(int j= 0; j<3; j++)
         {
            sum +=marks[i][j];
         }
         if(sum > sum2)
         {
            sum2 = sum;
            top = i;
         }
      }
      cout<<"\nStudent with highest marks is student"<<(top+1)<<"\n";
      cout<<"\nStudents Record : \n";
       for(int j =0; j<students; j++)
       {
         cout<<"\nName : "<<name[j]<<"\n";
         cout<<"Roll No. "<<rollno[j]<<"\n";
         cout<<"Marks for three subjects: \n";
         for(int k=0; k<3; k++)
         {
               cout<<marks[j][k]<<" ";
         }
         cout<<"\n";
         cout<<"Total marks : "<<sum2<<"\n";
      }
    }
};
int main()
{
   int n;
   cout<<"Enter the number of students in the database :\n";
   cin>>n;

   school s1(n);
   cout<<"\nEnter students details : \n";
   for (int i = 0; i<n; i++)
   {
      cout<<"\nStudent : "<<(i+1)<<"\n";
      s1.inputdata(i);
   }

   s1.display();
   
   char choice;
   cout<<"\nDo you want to calculate averages ? y/n\n";
   cin>>choice;
   if(choice == 'y')
   {
      s1.average();
   }

   cout<<"\nDo you want to find topper? y/n\n";
   cin>>choice;
   if(choice == 'y')
   {
      s1.Topper();
   }

   int new_n;
   cout<<"\nDo you want to add new student? y/n\n";
   cin>>choice;
   if(choice == 'y')
   {
      cout<<"\nHow many students u want to add?";
      cin >>new_n;

      s1.resize(new_n);

      cout<<"\nEnter students details : \n";
      for (int i = n; i<(new_n+n); i++)
      {
         cout<<"\nStudent : "<<(i+1)<<"\n";
         s1.inputdata(i);
      }
   }

   s1.display();

return 0;
}