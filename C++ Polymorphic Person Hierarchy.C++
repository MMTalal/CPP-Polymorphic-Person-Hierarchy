#include <iostream>
#include <string>
using namespace std;

// Base class representing a person
class Person {
    private:
        string Name;  // Variable to store the name of the person

    public:
        // Default constructor for Person class
        Person() 
        {
            Name = "";  // Initializing the name to an empty string
        }

        // Parameterized constructor for Person class to initialize the name
        Person(string Name) 
        {
            this->Name = Name;  // Setting the name of the person using the argument
        }

        // Setter for the name of the person
        void setName(string Name) 
        {
            this->Name = Name;  // Assigning the input name to the class member
        }

        // Getter to return the name of the person
        string getName() 
        {
            return Name;  // Returning the name of the person
        }

        // Virtual function to display basic information about the person
        virtual void getInfo() 
        {
            cout << "The person name is " << getName() << ", ";  // Printing person's name
        }

        // Virtual destructor for cleaning up when a Person object is destroyed
        virtual ~Person() 
        {
            cout << "Person is destroyed" << endl;  // Message indicating that the Person object is destroyed
        }
};

// Derived class representing a Student, inheriting from Person
class Student : public Person {
    private:
        float GPA;  // Variable to store the student's GPA

    // Private function to evaluate the GPA and display the corresponding message
    // The purpose of this function is to avoid duplicating code in the constructor and the setter, and instead it is called only to validate the input.
    void evaluateGPA(float GPA) 
    {
        if (GPA < 2.5) 
        {
            this->GPA = GPA;  // Set GPA value
            cout << "Your GPA is Acceptable" << endl;
        }
        else if (GPA >= 2.5 && GPA < 3.0) 
        {
            this->GPA = GPA;
            cout << "Your GPA is Fair" << endl;
        }
        else if (GPA >= 3 && GPA <= 3.2) 
        {
            this->GPA = GPA;
            cout << "Your GPA is Good" << endl;
        }
        else if (GPA >= 3.3 && GPA <= 3.6) 
        {
            this->GPA = GPA;
            cout << "Your GPA is Very good" << endl;
        } 
        else if (GPA >= 3.7 && GPA <= 4) 
        {
            this->GPA = GPA;
            cout << "Your GPA is Excellent / Top tier" << endl;
        } 
        else 
        {
            this->GPA = 0;  // Set GPA to 0 for invalid values
            cout << "Invalid GPA value." << endl;
        }
    }

    public:
        // Default constructor for Student class
        Student() 
        {
            GPA = 0;  // Initializing GPA to 0
        }

        // Parameterized constructor for Student class to initialize name and GPA
        Student(string Name, float GPA): Person(Name) 
        {
            evaluateGPA(GPA);  // Call the evaluateGPA function to set the GPA and display the message
        }

        // Setter for the GPA of the student
        void setGPA(float GPA) 
        {
            evaluateGPA(GPA);  // Set the GPA using the evaluateGPA function
        }

        // Getter for the student's GPA
        float getGPA() 
        {
            return GPA;  // Return the GPA value
        }

        // Overridden function to display information about the student
        void getInfo() override 
        {
            Person::getInfo();  // Call the base class getInfo() to print the name
            cout << "The GPA is " << getGPA() << endl;  // Print the student's GPA
        }

        // Destructor for Student class
        ~Student() 
        {
            cout << "Student is destroyed" << endl;  // Message indicating the Student object is destroyed
        }
};

// Derived class representing a Doctor, inheriting from Person
class Doctor : public Person {
    private:
        int Salary;  // Variable to store the doctor's salary

    // Private function to evaluate and set the salary for the doctor
    // The purpose of this function is to avoid duplicating code in the constructor and the setter, and instead it is called only to validate the input.
    void SalaryDoctor(int Salary) 
    {
        if (Salary < 0) 
        {
            this->Salary = 0;  // Set salary to 0 if a negative value is given
            cout << "Salary can't be negative!" << endl;
        }
        else 
        {
            this->Salary = Salary;  // Set the salary to the valid value
        }
    }

    public:
        // Default constructor for Doctor class
        Doctor() 
        {
            Salary = 0;  // Initialize salary to 0
        }

        // Parameterized constructor for Doctor class to initialize name and salary
        Doctor(string Name, int Salary): Person(Name) 
        {
            SalaryDoctor(Salary);  // Set the salary using SalaryDoctor function
        }

        // Setter for the doctor's salary
        void setSalary(int Salary) 
        {
            SalaryDoctor(Salary);  // Set the salary using SalaryDoctor function
        }

        // Getter for the doctor's salary
        int getSalary() 
        {
            return Salary;  // Return the salary value
        }

        // Overridden function to display information about the doctor
        void getInfo() override 
        {
            Person::getInfo();  // Call the base class getInfo() to print the name
            cout << "The salary is " << getSalary() << endl;  // Print the doctor's salary
        }

        // Destructor for Doctor class
        ~Doctor() 
        {
            cout << "Doctor is destroyed" << endl;  // Message indicating the Doctor object is destroyed
        }
};

int main() {
    // Creating a Person pointer to a Student object
    Person* person1 = new Student("Ali", 3.5);  // Creating a new Student named "Ali" with GPA 3.5

    // Creating a Person pointer to a Doctor object
    Person* person2 = new Doctor("Dr. Samir", 12000);  // Creating a new Doctor named "Dr. Samir" with salary 12000

    // Calling getInfo() function on person1 (which points to Student object)
    person1->getInfo();  // This will call Student's getInfo() method
    
    // Calling getInfo() function on person2 (which points to Doctor object)
    person2->getInfo();  // This will call Doctor's getInfo() method

    // Deleting the dynamically allocated person1 (Student object)
    delete person1;  // This will call the destructor of Student, which calls Person's destructor

    // Deleting the dynamically allocated person2 (Doctor object)
    delete person2;  // This will call the destructor of Doctor, which calls Person's destructor

    return 0;  // End of the program
}
