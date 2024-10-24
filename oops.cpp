#include <iostream>
using namespace std;

// Abstract class representing the base employee
class AbstrcatEmployee {
public:
    virtual void AskForPromotion() = 0; // Pure virtual function
};

// Employee class definition
class Employee : public AbstrcatEmployee {
private:
    string Name;    // Employee name
    string Company; // Employee company
    int Age;       // Employee age

public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void IntroduceYourSelf() {
        cout << "Name - " << Name << endl;
        cout << "Age - " << Age << endl;
        cout << "Company - " << Company << endl;
    }

    // Implementation of pure virtual function from base class
    void AskForPromotion() override {
        if (Age > 30) {
            cout << "You got promoted!" << endl;
        } else {
            cout << "No promotion." << endl;
        }
    }

    // Friend function declaration
    friend void DisplayEmployeeDetails(Employee& emp);
    
    // Function Overloading Example
    void SetAge(int age) {
        Age = age;
    }

    void SetAge(int age, const string& reason) {
        Age = age;
        cout << "Age set to " << age << " because: " << reason << endl;
    }
};

// Developer class inheriting from Employee
class Developer : public Employee {
public:
    string FavLanguage; // Favorite programming language

    Developer(string name, string company, int age, string favLanguage)
        : Employee(name, company, age), FavLanguage(favLanguage) {}

    // Overriding the AskForPromotion function
    void AskForPromotion() override {
        cout << "Developer Promotion Check: ";
        Employee::AskForPromotion(); // Call base class method
    }
};

// Friend function definition
void DisplayEmployeeDetails(Employee& emp) {
    cout << "Displaying Employee Details:" << endl;
    emp.IntroduceYourSelf();
}

// Main function
int main() {
    // Creating an instance of Employee
    Employee emp2("Aadarsh", "Youtube", 20);
    emp2.IntroduceYourSelf();
    emp2.AskForPromotion();

    // Demonstrating function overloading
    emp2.SetAge(25); // Calling SetAge(int)
    emp2.SetAge(30, "Birthday"); // Calling SetAge(int, string)

    // Creating an instance of Developer
    Developer dev("Alice", "Google", 35, "C++");
    dev.IntroduceYourSelf();
    dev.AskForPromotion();

    // Using friend function
    DisplayEmployeeDetails(emp2);
    DisplayEmployeeDetails(dev);

    // Demonstrating polymorphism
    AbstrcatEmployee* e = &dev; // Base class pointer referring to a derived class object
    e->AskForPromotion(); // Calls Developer's AskForPromotion method

    return 0;
}

// Concepts of OOP included:
// 1. **Encapsulation**: Data (Name, Age, Company) and methods (IntroduceYourSelf, AskForPromotion) are bundled together in the class.
// 2. **Abstraction**: The AbstrcatEmployee class provides an interface for derived classes (Employee, Developer) without exposing implementation details.
// 3. **Inheritance**: Developer class inherits from Employee class, allowing it to reuse code.
// 4. **Polymorphism**: A base class reference (AbstrcatEmployee*) can point to derived class objects (Developer), allowing dynamic method resolution.
// 5. **Friend Function**: `DisplayEmployeeDetails` is a friend function that can access private members of the Employee class.
// 6. **Function Overloading**: `SetAge` is overloaded with different parameter types.
// 7. **Function Overriding**: `AskForPromotion` is overridden in the Developer class, providing a specific implementation.

// oops - programming paradime
//      - represent entities with behaviour in program
// class - user defined datatype


  //pure virtual function : A virtual function lets you override a function in a base class with di f ferent version in a derived class. It ensures that the right version of the function is called, depending on the actual object being referenced, not the type of reference or pointer used to call the function.


// define class -- model or blue print of data

// constructor  -1. does not return type 2.name should be same to class name



//encapsulation -  idea of bundling or tieing together data and method that operate on data so they are grouped together in a class 
//              - purpose: preventing to directly acess the data or interaction and to modify it 

// the most common use of polymorphism is parent class reference is used to refer to a child object
// employee *e = &d;  

// Virtual Function:

// A function declared in a base class that can be overridden in a derived class. It supports runtime polymorphism.
// Friend Function:

// A function that is not a member of a class but has access to its private and protected members. It is declared in the class using the friend keyword.
// Function Overloading:

// Defining multiple functions with the same name but different parameter lists within the same scope.
// Function Overriding:

// Providing a new implementation for a virtual function in a derived class that already exists in the base class.


// Here's a breakdown and improvement of the C++ code, explaining key concepts of Object-Oriented Programming (OOP) and how they are implemented in the program:

// ---

// ### 1. **Class**
//    - A **class** is a blueprint for creating objects that encapsulate both data and functions. In the code, classes like `Employee` and `Developer` represent entities with attributes (data members) and methods (functions).

//    Example:
//    ```cpp
//    class Employee {
//        // Class members
//    };
//    ```

// ### 2. **Constructor**
//    - A **constructor** is a special function that initializes an object when it is created. It has the same name as the class and does not have a return type.
//    - In the `Employee` class, the constructor initializes the `Name`, `Company`, and `Age`.

//    Example:
//    ```cpp
//    Employee(string name, string company, int age) {
//        Name = name;
//        Company = company;
//        Age = age;
//    }
//    ```

// ### 3. **Encapsulation**
//    - **Encapsulation** is the bundling of data (attributes) and methods (functions) into a single unit, the class. It restricts access to certain details and helps maintain control over the data by using private members.
//    - The `Employee` class bundles `Name`, `Company`, and `Age` as private members, accessible only through public methods.

//    Example:
//    ```cpp
//    private:
//        string Name;
//        string Company;
//        int Age;
//    ```

// ### 4. **Abstraction**
//    - **Abstraction** hides the implementation details and exposes only the necessary functionality. In the code, `AbstrcatEmployee` (abstract class) provides a pure virtual function, `AskForPromotion`, which must be implemented by derived classes (`Employee` and `Developer`).

//    Example:
//    ```cpp
//    virtual void AskForPromotion() = 0;  // Pure virtual function
//    ```

// ### 5. **Inheritance**
//    - **Inheritance** allows a class to acquire properties and behavior (methods) from another class. In this case, `Developer` inherits from `Employee`, meaning it can use the data members and methods from `Employee` while adding its own.

//    Example:
//    ```cpp
//    class Developer : public Employee {
//        // Inherited from Employee
//    };
//    ```

// ### 6. **Polymorphism**
//    - **Polymorphism** allows objects of different classes to be treated as objects of a common base class. Here, a base class pointer (`AbstrcatEmployee*`) refers to a derived class object (`Developer`), and the correct method is called based on the object’s type.
//    - This is demonstrated through the use of virtual functions, which enable **runtime polymorphism**.

//    Example:
//    ```cpp
//    AbstrcatEmployee* e = &dev;  // Base class pointer
//    e->AskForPromotion();  // Calls Developer's AskForPromotion
//    ```

// ### 7. **Friend Function**
//    - A **friend function** is not a member of the class but can access its private and protected members. In the code, `DisplayEmployeeDetails` is declared as a friend of the `Employee` class, allowing it to access private members like `Name`, `Company`, and `Age`.

//    Example:
//    ```cpp
//    friend void DisplayEmployeeDetails(Employee& emp);  // Friend function declaration
//    ```

// ### 8. **Function Overloading**
//    - **Function overloading** allows multiple functions with the same name but different parameter lists. The correct function is chosen based on the arguments passed. In the code, `SetAge` is overloaded, once with a single integer argument and another with an additional string reason.

//    Example:
//    ```cpp
//    void SetAge(int age);               // Overloaded function 1
//    void SetAge(int age, string reason); // Overloaded function 2
//    ```

// ### 9. **Function Overriding**
//    - **Function overriding** occurs when a derived class provides a specific implementation for a virtual function that already exists in the base class. In the code, `Developer` overrides the `AskForPromotion` method, adding a custom message and then calling the base class version.

//    Example:
//    ```cpp
//    void AskForPromotion() override {
//        cout << "Developer Promotion Check: ";
//        Employee::AskForPromotion();  // Call base class method
//    }
//    ```

// ---

// ### Improvements and Notes:
// 1. **Typo Fix**: The abstract class should be named `AbstractEmployee` instead of `AbstrcatEmployee` to correct the typo.
//    ```cpp
//    class AbstractEmployee {
//        virtual void AskForPromotion() = 0;
//    };
//    ```

// 2. **Code Efficiency**: Use initializer lists in constructors for better performance and clarity.
//    ```cpp
//    Employee(string name, string company, int age) : Name(name), Company(company), Age(age) {}
//    ```

// 3. **Best Practice**: Instead of manually assigning private variables, consider using getter and setter functions to adhere to encapsulation principles more rigorously. This will control how the variables are accessed and modified.

// --- 

// This code demonstrates key OOP principles, making it a solid example for understanding how to design flexible and maintainable software.
