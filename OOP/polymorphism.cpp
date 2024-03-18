#include <iostream>
using std::string;

class AbstractEmployee{
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee{

private:
    
    string COmpany;
    int Age; 
protected:
    string name;

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
    // added virtual:
    // Will tell compiler to check for implementations in derived classes
    virtual void Work(){
        std::cout<< this->name <<" is checking mails and jira backlogs" << std::endl;
    }
    

};

// This inheritance of a super/parent class is pvt usually.
// class Developer: Employee{

// To make it public
class Developer:public Employee{

public:
    string favLang;

    Developer(string NAME, string COMPANY, int AGE, string favLang):Employee(NAME,COMPANY,AGE){
        this->favLang = favLang;
    }

    void fixBug(){
        std::cout<< name <<" fixed bug in"<< this->favLang <<std::endl;
    }

    void Work(){
        std::cout<< this->name <<" isreading from backlog. Then: "  << std::endl;
        this->fixBug();
    }
};


// Derived class
class Teacher:public Employee{
public:    
    string subject;

    Teacher(string NAME, string COMPANY, int AGE, string subject):Employee(NAME,COMPANY,AGE){
        this->subject = subject;
    }
    void PrepareLessons(){
        std::cout<< this->name<< "preps lessons for the class" << this->subject <<std::endl;
    }
    // void Work(){
    //     std::cout<< this->name <<" is checking mails. Then"<< std::endl;
    //     this->PrepareLessons();
    // }
};
int main()
{
    Employee emp1 = Employee("AMX", "unemployed",26 );
    Developer AMX = Developer("Amudhesh", "HFT", 26, "Cpp");
    // AMX.fixBug();
    // AMX.AskForPromotion();

    Teacher Saladin = Teacher("Saladin", "HFT", 31, "Low LAtency prog with Cpp");
    // Saladin.PrepareLessons();
    // Saladin.AskForPromotion();

    // AMX.Work();
    // Saladin.Work();

    Employee* e1 = &AMX;
    e1->Work();
    Employee* e2 = &Saladin;
    e2->Work();

}