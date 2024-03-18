#include <iostream>
using std::string;

class Employee{
private:
    string name;
    string COmpany;
    int Age; 


public:
// Inside the constructor, you are trying to assign the parameters to the class member variables. 
// However, since the parameter names are the same as the class member variable names, 
// the assignments are not working as expected.

//  In C++, if a local variable (in this case, the constructor parameters)
//  has the same name as a class member variable, the local variable will hide the class member variable.
//  This is known as variable shadowing.

// To fix this, you should use the "this" pointer to refer to the class member variables:
    // constructor has no return type speciifed.
    // Same name as class
    Employee(string name, string COmpany, int Age) {
        this->name = name;
        this->COmpany = COmpany;
        this->Age = Age;

    }

    void IntoduceYOurself() {
        std::cout << "Name :" << name << std::endl;
        std::cout << "Age :" << Age << std::endl;
    }
};

int main()
{
    Employee emp1 = Employee("AMX", "unemployed",26 );
    
    emp1.IntoduceYOurself();

    Employee emp2 = Employee("John", "ONI",26 );
    
    emp2.IntoduceYOurself();

}