#include <iostream>
using std::string;

class Employee{
private:
    string name;
    string COmpany;
    int Age; 


public:

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
    emp1.setAge(12);
    emp1.setname("Looser");
    emp1.setAge(26);

    std::cout << emp1.getName() << std::endl;

    Employee emp2 = Employee("John", "ONI",26 );
    
    emp2.IntoduceYOurself();

}