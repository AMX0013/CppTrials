#include <iostream>
using namespace std;

/*
A void pointer, also known as a generic pointer, is a special type of pointer that can be pointed to any data type's objects.
 In C++, it is declared using the keyword void. For example:
*/


void printNumber(int* numPtr){
    cout<< *numPtr << endl;
}

void printNumber(char* numPtr){
    cout<< *numPtr << endl;
}

void print(void* ptr, char type){
    // can store pointer of any type
    // cannot be dereferenced directly, it'll de-reference returning garbage
    switch (type){
        case 'i' : cout << *((int*)ptr) << endl;  break;  //handle int* 
        case 'c' : cout << *((char*)ptr)<<endl;   break;  //handle char* 
    }
}

int main()
{
    int number = 5;
    char letter = 'c';

    // printNumber(&number);
    // printNumber(&letter);

    print(&number, 'i');
    print(&letter, 'c');


    return 0;
}
