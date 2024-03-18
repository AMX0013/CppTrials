#include <iostream>
using std::string;
/*
Implements: This keyword is used when a class wants to use an interface. 
An interface is a completely abstract class that contains only abstract methods (methods without a body). 
When a class "implements" an interface, it provides the bodies for the interface's abstract methods.
 It's a way of setting up a contract for what a class can do, without specifying how the class will do it.

*/
class AbstractEmployee{
    virtual void AskForPromotion() = 0;
};

// class Employee is implementing abstract class AbstractEmployee. Therefore extends Employee?
/*Extends: This keyword is used to inherit from a class or interface.
 In languages like Java, you use "extends" to create a child class of a parent class. This is similar to "inherits". 
 The child class "extends" the parent class, meaning it gets all the fields and methods of the parent class, plus it can add more.
 In the case of an interface, "extends" is used when one interface inherits another interface.
 */
class Employee:AbstractEmployee{

private:
    string name;
    string COmpany;
    int Age; 


public:

    void AskForPromotion(){
        if (Age >= 30)
            std::cout<<this->name<< "can be promoted" <<std::endl;
        else
            std::cout<< this->name<< "cannot be promoted"  <<std::endl;
    }

    void setAge(int Age){
        if (this->Age >= 18){
            this->Age = Age;
            std::cout << "age checks out, Age changed, New Age: "<< this->Age <<std::endl;

        }
        else
        {
            std::cout << "too young to change your own Age"<<std::endl;
        }
        
        
    }

    int getAge(){
        return this->Age;
    }


    void setname(string Name){
        if (this->Age >= 18){
            
            this->name = Name;
            std::cout << "age checks out, name changed. New name:"<< this->name <<std::endl;
        }
        else
        {
            std::cout << "too young to change your own name"<<std::endl;
        }
        
        
    }

    string getName(){
        return this->name;
    }


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
    emp1.setname("Amudhesh");
    emp1.AskForPromotion();
    
    emp1.setAge(30);
    emp1.AskForPromotion();

    std::cout << emp1.getName() << std::endl;

    Employee emp2 = Employee("John", "ONI",26 );
    
    emp2.IntoduceYOurself();

}


