#include <iostream>
#include <vector>
using namespace std;

// Base class representing an Airport
class Airport
{
    protected:
        string name;
        string location;
        int code;
    public:
        Airport(){}
        ~Airport(){}
         // Parameterized constructor
        Airport(string n, string loc, int c)
        {
            name = n;
            location = loc;
            code = c;
        }

         // Setters
        void setname(string name)
        {
            this->name = name;
        }  
        void setLocation(string location)
        {
            this->location = location;
        }  
        void setCode(int code)
        {
            this->code = code;
        }
        
        
        // Getters
        string getname()
        {
            return name;
        }
        string getlocation()
        {
            return location;
        }
        int getcode()
        {
            return code;
        }

        // Copy constructor
        Airport(const Airport &other)
        {
            name = other.name;
            location = other.location;
            code = other.code;
            cout << "Airport copy constructor called.\n";
        }

         // Virtual function for polymorphism
        virtual void display()
        {
            cout<<"\n-----------Airport Details-------------\n";
            cout<<"\nAirport: "<<name<<"\n";
            cout<<"Location: "<<location<<"\n";
            cout<<"Airport code: "<<code<<"\n";
        }
};

// Flight class inherits from Airport
class Flight : public Airport
{
   protected: 
    string flightNumber;
    string destination;
    string departureTime;
    string arrivalTime;
    int total_seats;
    int booked_seats;

  
  public:
     Flight() {};
     virtual ~Flight() {};

     // Constructor that also initializes Airport
     Flight(string flightno, string dest, string depttime, string arrtime, int t_seats, int b_seats, string airportName, string airportLocation, int airportCode)
: Airport(airportName, airportLocation, airportCode), flightNumber(flightno),destination(dest),departureTime(depttime),arrivalTime(arrtime),total_seats(t_seats),booked_seats(b_seats)
{}

	  
    // Input flight data
	 void input()
	  {
	  	cout<<"Enter Flight No. "<<endl; 
	  	getline(cin, flightNumber);
	  	cin.ignore();

	  	cout<<"Enter destination:"<<endl;  
	  	getline(cin, destination);
	  	 cin.ignore();

	  	cout<<"Enter Departure time:"<<endl;
	  	getline(cin, departureTime);
	  	  cin.ignore();

	  	cout<<"Enter arrival time:"<<endl;
	  	getline(cin, arrivalTime);
          cin.ignore();
	  }
    
      // Getters
      string getflightnum()
      {
        return flightNumber;
      } 

      string getdestination()
      {
        return destination;
      } 

      string getdeparture()
      {
        return departureTime;
      } 

      string getarrival()
      {
        return arrivalTime;
      }

      int gettotalseats()
      {
        return total_seats;
      } 

      int getbookedseats()
      {
        return booked_seats;
      } 

      // Check if seat is available
	  bool is_seatavailable()
	  {
	  	return booked_seats<total_seats;
	  }
	  // Change flight timings
	  void changeTime(string departtime , string arritime)
	  {
	  	departureTime = departtime;
	  	arrivalTime = arritime;
	  }

	  // Override display for polymorphism
	   void display()
	  {
        Airport::display();
	    cout<<"\n------------------Flight Details------------------------\n\n";
	  	cout<<"Flight Number : "<<flightNumber<<endl;
	  	
	  	cout<<"Destination : "<<destination<<endl;
	  	
	  	cout<<"Departure Time : "<<departureTime<<endl;
	
	  	cout<<"Arrival Time : "<<arrivalTime<<endl;
	  	
	  	
          if (is_seatavailable())
          {
              cout << "Seat is Available." << endl;
          }
          else
          {
              cout << "No seats available" << endl;
          }
        }
    };

    // Airline class demonstrating aggregation of Flights
    class Airline
    {
        private:
            string airline_name;
            string airline_code;
            Flight* flights; // Array of flights (aggregation)
            int num_flights;

        public: 
            Airline(){};
            ~Airline()
            {
                delete[] flights;
            }
            // Constructor with flight array
            Airline(string name, string code, int n, Flight* flights_list )
            {
                airline_name = name;
                airline_code = code; 
                num_flights = n;
                flights = new Flight[n];
                for(int i= 0 ; i<n; i++)
                {
                    flights[i] = flights_list[i];
                }
            }
            
             // Add a new flight to airline
            void addflight(const Flight &newflight)
            {
                Flight* newflights;
                newflights = new Flight[num_flights+1];
                for(int i=0; i<num_flights; i++)
                {
                    newflights[i] = flights[i];
                }
                delete flights;
                flights = newflights;
                num_flights++;
                newflights[num_flights] = newflight;
                flights = newflights;

            }

            // Remove a flight from airline
            void removeflight( Flight &cancelflight)
            {
                for(int i= 0 ; i<num_flights; i++)
                {
                    if(flights[i].getflightnum() == cancelflight.getflightnum())
                    {
                        for(int j= i; j<num_flights-1; j++)
                        {
                            flights[j] = flights[j+1];
                        }
                    num_flights--;
                    break;
                    }
                else
                    cout<<"Flight not found";
                }
            }

             // Display airline details
            void display()
            {
                cout<<"\n-------------------Airline Details-------------------\n";
                cout<<"\nAirline : "<<airline_name<<endl;
                cout<<"Airline Code : "<<airline_code<<endl;
                cout<<"Number of Flights : "<<num_flights<<endl;
                for(int i =0; i<num_flights;i++)
                {
                    flights->display();
                }
            }
    };

    // Staff class (inherits Airport)
    class Staff : public Airport
    {
        private:
            int emp_id;
            string emp_name;
            double salary;
            int emp_contact;
            string role;
            vector<string> tasks; 
        public:
            Staff(){};
            Staff(string air_name, string loc, int code, int id, string name, double sal, int cont,string r) : Airport(air_name,loc,code), emp_id(id), emp_name(name), salary(sal), emp_contact(cont), role(r) {};
            virtual ~Staff()
            {
                cout<<"Staff destroyed\n";
            }

            // Display assigned tasks
            void viewtasks()
            {
                for(int i=0; i<tasks.size(); i++)
                {
                    cout<<"Assigned tasks: \n";
                    cout<<tasks[i]<<endl;
                }
            }
        //setters
        void set_id(int id);
        void set_name(string name);
        void set_salary(double salary);
        void set_contact(int contact);
        void set_role(string role);
        //getters
        int get_id() const;
        string get_name() const;
        double get_salary() const;
        int  get_contact() const;
        string get_role()  const;
        //functions
        void remove_task();
        void assign_task(const string task);


    // Display staff info
        void display()
        {
            Airport :: display();

            cout<<"\n----------------------Employee Details--------------------- \n\n";
            cout<<"Name : "<<emp_name<<endl;
            cout<<"ID : "<<emp_id<<endl;
            cout<<"Contact No. "<<emp_contact<<endl;
            cout<<"Salary : "<<salary<<endl;
            cout<<"Role : "<<role<<endl;
            viewtasks();
        }   
    };
void Staff::set_id(int id)
{
    emp_id = id;
}
void Staff::set_name(string name)
{
    emp_name = name;
}
void Staff::set_salary(double salary)
{
    this->salary = salary;
}
void Staff::set_contact(int contact)
{
    emp_contact=contact;
}
void Staff::set_role(string role)
{
     this->role=role;
}
int Staff::get_id() const
{
    return emp_id;
}
string Staff::get_name()const
{
    return emp_name;
}
double Staff::get_salary()const
{
    return salary;
}
int Staff::get_contact()const
{
    return emp_contact;
}
string Staff::get_role()const
{
    return role;
}
void Staff::assign_task(const string task)
{
   
    tasks.push_back(task); // add task to the list 
    cout << "Task assigned to " << get_name() << ": " << task << endl;
}
void Staff::remove_task()
{
    tasks.pop_back();
    cout << tasks.back() << "/Task Removed"<<endl;
}

// Baggage class used by Passenger (composition)
class Baggage
{
private:
    int baggageID;
    double weight;
    string type;
    string status;

public:
    Baggage() {}
    ~Baggage() {}

    Baggage(int id, double w, string t) : baggageID(id), weight(w), type(t) {}

    // Getters
    int getID() const 
    { 
        return baggageID; 
    }
    double getWeight() const 
    { 
        return weight; 
    }
    string getType() const 
    { 
        return type; 
    }

    void display()
    {
        cout<<"\n------------Baggage Details-----------------\n\n";
        cout << "Baggage ID: " << baggageID << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Type: " << type << endl;
    }

    

    void checkSecurity()
    {
        cout << "Security check in progress for baggage ID: " << baggageID << "...\n";
        // Simulate security check (this could be made dynamic later)
        cout << "Baggage ID: " << baggageID << " passed security check.\n";
    }

    void trackBaggage()
    {
        cout << "Tracking baggage ID: " << baggageID << endl;
        cout << "Current status: " << status << endl;
    }

    void updateStatus(const string &new_status)
    {
        status = new_status;
        cout << "Status of baggage ID " << baggageID << " updated to: " << status << endl;
    }


};

// Passenger class inherits Airport, has a list of Baggage (composition)
class Passenger : public Airport
{
protected:
    string name;
    int id;
    int contact;
    string passportnumber;
    vector<Baggage> baggageList;

public:
    Passenger() {}
    virtual ~Passenger() {}

    Passenger(string airname, string loc, int code,string pname, int pid, int cont, string pass_no)
        : Airport(airname, loc, code), name(pname), id(pid), contact(cont), passportnumber(pass_no) {}

    string get_name() 
    { 
        return name;
    }
    int get_id() 
    { 
        return id; 
    }
    int get_contact() 
    { 
        return contact; 
    }
    string get_passport() 
    { 
        return passportnumber; 
    }

    // New: Register passenger
    void registerPassenger()
    {
        cout << "\n---------------Registering Passenger-----------------\n\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Contact Number: ";
        cin >> contact;
        cout << "Enter Passport Number: ";
        cin.ignore();
        getline(cin, passportnumber);
        cout << "\n------------Passenger registered successfully--------------------------\n\n";
    }

    // New: Check-in method
    void checkIn()
    {
        cout << "\nChecking in passenger: " << name << "\n";
        cout << "Passport: " << passportnumber << "\n";
        cout << "Contact: " << contact << "\n";
        cout << "Check-in completed successfully.\n";
    }
    friend class Baggage; // Declared as a friend

    void addBaggage(const Baggage &b)
    {
        baggageList.push_back(b);
        cout << "\nBaggage added for passenger: " << name << endl;
    }

    void showBaggage()
    {
        cout << "\nBaggage details for passenger: " << name << endl;
        for (size_t i = 0; i < baggageList.size(); ++i) 
        {
            baggageList[i].display();
            cout << "----------------------\n";
        }
        
    }

    virtual void display()
    {
        Airport::display();
        cout << "\n-------------------Passenger Details----------------------\n\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Contact: " << contact << endl;
        cout << "Passport Number: " << passportnumber << endl;
    }
};

// Ticket class inherits Passenger and includes Flight (composition)
class Ticket : public Passenger
{
    private:
        string ticket_number;
        string seat_number;
        Flight flight;
        double price;
        string ticket_class;
    public:
        Ticket(){};
        virtual ~Ticket()
        {
            cout<<"Ticket destroyed";
        }
        Ticket(string airname, string loc, int code, string p_name, int p_id, int p_cont, string pass_num, string t_num, string s_num, const Flight f, double p, string t_class)
         : Passenger(airname, loc, code, p_name, p_id, p_cont, pass_num),ticket_number(t_num), seat_number(s_num), flight(f), price(p), ticket_class(t_class) {}

         // Getters
        string get_ticket_num()
        {
            return ticket_number;
        }

        string get_seat_num()
        {
            return seat_number;
        }

        Flight get_flight()
        {
            return flight;
        }

        double get_price()
        {
            return price;
        }

        string get_ticket_class()
        {
            return ticket_class;
        }
         // Ticket operations
        void BookTicket()
        {
            if (flight.is_seatavailable())
            {
                cout << "\nTicket " << ticket_number << " booked successfully for flight " << flight.getflightnum() << endl;
            }
            else
            {
                cout << "\nCannot book ticket. No seats available for flight " << flight.getflightnum() << endl;
            }
        }

        void CancelTicket()
        {
            cout << "\nTicket " << ticket_number << " has been cancelled for passenger " << name << "." << endl;
        }

        void display() 
        {
            Passenger::display();
            cout << "\n---------------Ticket Information-----------------\n\n";
            cout << "Ticket Number: " << ticket_number << endl;
            cout << "Seat Number: " << seat_number << endl;
            cout << "Class: " << ticket_class << endl;
            cout << "Price: $" << price << endl;
            flight.display();
        }
};

int main()
{
    // Create a list of flights and initialize airline, staff, passenger, and ticket objects
    vector<Flight> flightList;
    Airline airline;
    Staff staff;
    Passenger passenger;
    Ticket ticket;

    // Pre-defined flights for demonstration
    Flight f1("AA101", "Los Angeles", "08:00 AM", "11:30 AM", 150, 100, "JFK International", "New York", 101);
    Flight f2("AA202", "Miami", "02:00 PM", "05:00 PM", 200, 180, "JFK International", "New York", 101);
    Flight flightArray[2] = {f1, f2};

    // Initialize airline with pre-defined flights
    airline = Airline("American Airlines", "AA", 2, flightArray);

    int choice; // Variable for user menu selection

    // Menu loop starts
    do
    {
        // Display menu options
        cout << "\n----------- Airport Management System Menu ---------\n";
        cout << "1. Display Airport Info\n";
        cout << "2. Display Flights\n";
        cout << "3. Add a Flight to Airline\n";
        cout << "4. Remove a Flight from Airline\n";
        cout << "5. Display Airline Details\n";
        cout << "6. Register Staff and Assign Tasks\n";
        cout << "7. Register Passenger and Check-in\n";
        cout << "8. Add Baggage for Passenger\n";
        cout << "9. Show Passenger Baggage\n";
        cout << "10. Book and Cancel Ticket\n";
        cout << "11. Demonstrate Polymorphism\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user choice with switch-case
        switch (choice)
        {
        case 1:
        {
            // Display basic airport info
            Airport a1("JFK International", "New York", 101);
            a1.display();
            break;
        }
        case 2:
        {
            // Display all flights
            for (int i = 0; i < 2; ++i)
                flightArray[i].display();
            break;
        }
        case 3:
        {
            // Add a new flight to the airline
            string fn, dest, dep, arr;
            int ts, bs;
            cout << "Enter Flight No: "; 
            cin.ignore();
            getline(cin, fn);

            cout << "Enter Destination: ";
            cin.ignore();
            getline(cin, dest);

            cout << "Enter Departure Time: ";
            cin.ignore();
            getline(cin, dep);

            cout << "Enter Arrival Time: ";
            cin.ignore();
            getline(cin, arr);

            cout << "Enter Total Seats: "; cin >> ts;
            cout << "Enter Booked Seats: "; cin >> bs;

            Flight newFlight(fn, dest, dep, arr, ts, bs, "JFK International", "New York", 101);
            airline.addflight(newFlight);
            cout << "Flight added to airline.\n";
            break;
        }
        case 4:
        {
            // Remove a flight from the airline using flight number
            string fn;
            cout << "Enter Flight Number to Remove: ";
            cin >> fn;
            Flight temp(fn, "", "", "", 0, 0, "", "", 0); // Minimal temp flight for comparison
            airline.removeflight(temp);
            break;
        }
        case 5:
        {
            // Display all airline details
            airline.display();
            break;
        }
        case 6:
        {
            // Register a staff member and assign/remove tasks
            Staff staff1("JFK International", "New York", 101, 201, "Emily Smith", 55000, 987654321, "Security");
            Staff staff2("JFK International","New York",101,980, "John Carter", 670000, 9234568907, "Pilot");
            staff.assign_task("Inspect Luggage");
            staff.assign_task("Boarding Assistance");
            staff.remove_task(); // Remove last assigned task
            staff.display(); // Display staff info
            break;
        }
        case 7:
        {
            // Register a passenger and check in
            passenger.registerPassenger();
            passenger.checkIn();
            passenger.display(); // Show passenger info
            break;
        }
        case 8:
        {
            // Add baggage for the passenger
            int id;
            double weight;
            string type;
            cout << "Enter Baggage ID: ";
            cin >> id;
            cout << "Enter Weight: ";
            cin >> weight;
            cout << "Enter Type (e.g., Carry-on/Checked-in): ";
            cin.ignore();
            getline(cin, type);

            Baggage bag(id, weight, type);
            bag.checkSecurity();         // Simulate security check
            bag.updateStatus("Loaded");  // Update baggage status
            passenger.addBaggage(bag);   // Add baggage to passenger
            break;
        }
        case 9:
        {
            // Show all baggage linked to the passenger
            passenger.showBaggage();
            break;
        }
        case 10:
        {
            // Book a ticket and then cancel it
            ticket = Ticket("JFK International", "New York", 101, passenger.get_name(), passenger.get_id(),
                            passenger.get_contact(), passenger.get_passport(), "T001", "14B", f1, 300.0, "Economy");
            ticket.BookTicket();   // Simulate booking
            ticket.display();      // Show ticket info
            ticket.CancelTicket(); // Cancel ticket
            break;
        }
        case 11:
        {
            // Demonstrate polymorphism using base class pointer
            Airport *ptr;

            ptr = &f1;
            ptr->display(); // Call Flight's display

            ptr = &staff;
            ptr->display(); // Call Staff's display

            ptr = &passenger;
            ptr->display(); // Call Passenger's display

            ptr = &ticket;
            ptr->display(); // Call Ticket's display
            break;
        }
        case 0:
            // Exit condition
            cout << "Exiting system.\n";
            break;
        default:
            // Handle invalid menu input
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0); // Repeat until user chooses to exit

    return 0; // End program
}
