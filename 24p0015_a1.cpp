#include <iostream>
using namespace std;

// Doctor Structure: Stores doctor details
struct Doctor 
{
    string dr_name;       // Doctor's Name
    string specialization; // Specialization field
    string gender;        // Gender of the doctor
    int yearsof_exp;      // Years of experience
};

// Patient Structure: Stores patient details and nested doctor structure
struct Patient
 {
    string p_name;        // Patient's Name
    int age;             // Patient's Age
    string gender;       // Patient's Gender
    string disease;      // Disease patient is diagnosed with
    Doctor assigned_dr;  // Doctor assigned to the patient
};

// Hospital Structure: Contains hospital details and dynamically allocated patient list
struct Hospital 
{
    string h_name;       // Hospital Name
    string location;     // Hospital Location
    Patient* patients;   // Pointer to dynamically allocated patient array
    int num_patients;    // Number of admitted patients
};

// Function to input patient details
void input_patients(Hospital* hos, int n) 
{
    hos->num_patients = n;         // Set the number of patients
    hos->patients = new Patient[n]; // Dynamically allocate memory for patients

    cout << "Enter Patients details : \n";
    for (int i = 0; i < n; i++) {
        cout << "\nPatient Name : ";
        cin >> hos->patients[i].p_name;
        cout << "Age : ";
        cin >> hos->patients[i].age;
        cout << "Gender : ";
        cin >> hos->patients[i].gender;
        cout << "Disease : ";
        cin >> hos->patients[i].disease;

        // Input assigned doctor's details
        cout << "\nAssigned Doctor Details : \n";
        cout << "\nDoctor Name : ";
        cin >> hos->patients[i].assigned_dr.dr_name;
        cout << "Specialization : ";
        cin >> hos->patients[i].assigned_dr.specialization;
        cout << "Gender : ";
        cin >> hos->patients[i].assigned_dr.gender;
        cout << "Years of Experience : ";
        cin >> hos->patients[i].assigned_dr.yearsof_exp;
    }
}

// Function to admit a new patient (dynamically reallocates memory)
void admit(Hospital* hos) 
{
    hos->num_patients++; // Increase patient count
    int n = hos->num_patients - 1;

    // Create a new dynamically allocated array with extra space
    Patient* newpatients = new Patient[hos->num_patients];

    // Copy old patient details to the new array
    for (int i = 0; i < n; i++) 
    {
        newpatients[i] = hos->patients[i];
    }

    // Input new patient details
    cout << "Enter Patient details : \n";
    cout << "\nPatient Name : ";
    cin >> newpatients[n].p_name;
    cout << "Age : ";
    cin >> newpatients[n].age;
    cout << "Gender : ";
    cin >> newpatients[n].gender;
    cout << "Disease : ";
    cin >> newpatients[n].disease;

    // Input assigned doctor's details
    cout << "\nAssigned Doctor Details : \n";
    cout << "\nDoctor Name : ";
    cin >> newpatients[n].assigned_dr.dr_name;
    cout << "Specialization : ";
    cin >> newpatients[n].assigned_dr.specialization;
    cout << "Gender : ";
    cin >> newpatients[n].assigned_dr.gender;
    cout << "Years of Experience : ";
    cin >> newpatients[n].assigned_dr.yearsof_exp;

    // Free old memory and assign new array
    delete[] hos->patients;
    hos->patients = newpatients;
}

// Function to display all patient details
void display(Hospital* hos) 
{
    cout << "Patients details : \n";
    for (int i = 0; i < hos->num_patients; i++) 
    {
        cout << "\nPatient Name : " << hos->patients[i].p_name;
        cout << "\nAge : " << hos->patients[i].age;
        cout << "\nGender : " << hos->patients[i].gender;
        cout << "\nDisease : " << hos->patients[i].disease;
        cout << "\nAssigned Doctor Details : \n";
        cout << "\nDoctor Name : " << hos->patients[i].assigned_dr.dr_name;
        cout << "\nSpecialization : " << hos->patients[i].assigned_dr.specialization;
        cout << "\nGender : " << hos->patients[i].assigned_dr.gender;
        cout << "\nYears of Experience : " << hos->patients[i].assigned_dr.yearsof_exp;
    }
}

// Function to discharge a patient by shifting remaining patients
void discharge(Hospital* hos, int i) 
{
    i--; // Convert user input to zero-based index
    cout << "\nPatient " << hos->patients[i].p_name << " is discharged.\n";

    // Shift patients to remove the discharged one
    for (int j = i; j < hos->num_patients - 1; j++) 
    {
        hos->patients[j] = hos->patients[j + 1];
    }
    hos->num_patients--; // Decrease patient count
}

// Function to free dynamically allocated memory
void freemem(Hospital* hos) 
{
    delete[] hos->patients;
    hos->patients = NULL;
}

int main() 
{
    Hospital hos; // Create a hospital instance
    int choice, n, index;

    // Input hospital details
    cout << "Enter Hospital Name: ";
    getline(cin, hos.h_name);
    cout << "Enter Hospital Location: ";
    getline(cin, hos.location);

    cout << "Enter initial number of patients: ";
    cin >> n;

    // Call function to input patient details
    input_patients(&hos, n);

    do 
    {
        // Display menu options
        cout << "\n--- HOSPITAL MANAGEMENT SYSTEM ---\n";
        cout << "1. Admit a new Patient\n";
        cout << "2. Display all Patients\n";
        cout << "3. Discharge a Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                // Admit a new patient
                admit(&hos);
                break;
            case 2:
                // Display all patients
                display(&hos);
                break;
            case 3:
                // Discharge a patient
                cout << "Enter Patient number to discharge : \n";
                cin >> index;
                
                    discharge(&hos, index);
        
                break;
            case 4:
                // Exit the program
                cout << "Exiting \n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
     while (choice != 4);

    // Free allocated memory before exiting
    freemem(&hos);

    return 0;
}
