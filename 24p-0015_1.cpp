#include <iostream>
using namespace std;
class num_collection
{   
  private:  
    int size; //number of elements stored in array
    int capacity;//size of the array
    int* arr;//pointer for dynamic array
  public:
  //default constructor
    num_collection()
    {
        size =0;
        capacity = 5;//size of array set to 5
        arr = new int[capacity];
    }
    //parameterized constructor
    num_collection( int c )
    {
        size = 0;
        
        if (c>0 && c<100) //checking valid capacity selection
        { 
           capacity =c;
           arr = new int[c];
        }
        else //if invalid capacity
        {
           cout<<"Invalid Capacity. Setting default\n ";
           
           capacity = 5;//setting to default capacity 5
           arr = new int[capacity];
        }
    }
    //destructor to free space
    ~num_collection()
    {
      delete[] arr;
      arr = NULL;
    }
    //adding number to the array, increasing size of array if needed
    void set_num(int num)
    {  
      if (size == capacity)//checking if array is full to double capacity
       {
          int* arr2 = new int[capacity*2];//new array of double size
          for(int i=0; i<size; i++)          
          {
            arr2[i] = arr[i];//copy old elements in new array
          }
          arr2[size] = num; //adding new element
          size++;//increasing the number of elements with addition of new elements
          
          arr = arr2;//storing new array address in arr
          capacity *= 2;//doubling capacity
       }
      else // if no increase in capacity needed
       {  
         arr[size]=num;
         size++;//increasing number of elements with addition of new elements
       }  
    }
    //return number at a specific index
    int get_num(int i)
    {
       if(i>size)
         return -1;//invalid index
       
       else
         return arr[i-1];//return number at index
    }
    //modifying number at an index
    void modify_num(int i , int n)
    { 
      if(i>size)//checking invalid index
         cout<<"The index choosen is out of bounds of the array.\n";
      else
         arr[i-1] = n;//modifying number
    }
    //displaying all elements of array
    void display()
    {
       for(int i=0; i<size; i++)
       {
        cout<<arr[i]<<" ";
       }
       cout<<endl;
    }
    //finding index of a  number if present
    int find_num(int num)
    {
       for(int i =0; i<size; i++)
       {
        if(arr[i] == num)
        return (i+1);//returning index if number present
       }
       return -1;//number not found
    }
    //returning number of empty spaces in array
    int empty_slots()
    { 
      int count =0;
      for(int i=0; i<capacity;i++)
      {
        if(arr[i]==0)
        count++;//counting the empty spaces 
      }
      return count;//returing the count of empty spaces
    }
    //returning total number of elements
    int count_elements()
    {
      return size;//size stores the number of elements
    }
    //looking for duplicates
    bool is_duplicate(int num)
    {
      int i = find_num(num);//first checking if number is present 
      if(i == -1)//if number not present
        return false;
      else
      { int count = 0;
        for(int j = 0; j<size; j++)//loop to look for the number of duplicates
        {
           if(arr[j] == num)
           count++;
        }
        if(count >1)//if the number is present more than once then return true
         return true;
        else
         return false;
      }
    }
   
};
int main()
{
  num_collection c1;//creating object with default constructor
  c1.set_num(10);//adding numbers to c1 array
  c1.set_num(20);
  c1.set_num(30);

  cout<<"array of c1: \n";
  c1.display();//displaying elements of c1 array

  //displaying empty spaces and number of elemnets in c1 array
  cout<<"Number of empty slots in c1: "<<c1.empty_slots();
  cout<<"\n";
  cout<<"Number of elements in c1: "<<c1.count_elements();
  cout<<"\n";

  c1.set_num(40);
  c1.set_num(50);

  c1.set_num(60);//this is 6th element in capacity of 5 so array capacity will be doubled
  
  cout<<"array of c1: \n";
  c1.display();//displaying elements of c1 array
  cout<<"Number of empty slots in c1: "<<c1.empty_slots();//number of spaces left in array after increasing capacity
  cout<<"\n";
  cout<<"Number of elements in c1: "<<c1.count_elements();//number of elements in array after increaing capacity
  cout<<"\n";

  
  int c;//variable c to take capacity from user
  int n;//variable n to take no. of elemnts from user
  cout<<"Enter the capacity of the array you want: ";
  cin>> c;//capacity of array taken from user
  num_collection c2(c);//making object with parameterized constructor with requested capacity

  cout<<"Enter the number of values you want to add in array: ";
  cin >> n;//taken number of elements that the user wants to add in arrray
  int num;
  //tsking values from user by loop to add in array c2
  cout<<"Enter the values you want to store.\n";
  for(int i=0; i<n; i++)
  { 
    cin >> num;//taking number to add
    c2.set_num(num);//adding number by function
  }
  cout<<"array of c2: \n";
  c2.display();//displaying elemts of c2 array
  
  //using get_num function
  int i;//variable to take index from user
  cout<<"Enter any index you want to get the value of : ";
  cin>> i;//taking index from user to fetch number on that index
  cout<<c2.get_num(i)<<"\n";//calling get_num function

  //using modify_num function
  cout<<"Enter the index whose value you want to modify and then enter the number you want to change it with : ";
  cin >> i >>  num; //taking index and a new number to modify at the index
  c2.modify_num(i, num);//calling modify_num function


  //using find_num function
  cout<<"Enter the number whose index you want to find: ";
  cin >>num;//taking num from user to find its index
  if(c2.find_num(num) == -1)//caling find_num functionif it is equal to -1 which means number not found
     cout<<"Number not found.";
  else//if number is found
     cout<<"Number lies in the index:  "<<c2.find_num(num);
  cout<<"\n";
  //displaying number of empty spaces and no. of elements in c2 array
  cout<<"Number of empty slots in c2 : "<< c2.empty_slots()<<"\n";
  cout<<"Number of elements in c2 : "<< c2.count_elements()<<"\n";
  
  //using is_duplicate function
  cout<<"Enter the number you want to check if it has a duplicate: ";
  cin>> num;//taking number from user to see if it has a duplicate
  if( c2.is_duplicate(num) )//calling function if it returns true
  cout<<"Yes this number has a duplicate\n";
  else//if it returns false
  cout<<"It has no duplicate\n";
  
  cout<<"array of c2: \n";
  c2.display();//displaying elements of c2
  return 0;
}
    
  
    
