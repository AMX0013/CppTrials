#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    cout << n <<endl;
    // obtain address
    int* ptr = &n; 
    cout << ptr <<endl;
    cout << &n <<endl;
    
    // dereferencing a ptr: to obtain value at a address
    cout << *ptr <<endl;

    // accessing and modifying value at an address
    *ptr = 10;
    cout << *ptr <<endl;
    cout << n <<endl;
    // Note pointer should be of same type as the variable its pointing to

    /*
    int* ptr2;
    *ptr2 = 7
    // The above code is wrtong. U cannot create a pointer. u can only create a variable and a pointer out of the varaible it
    */
    // create var
    int v;
    // create ptr from  v's address
    int* v_ptr = &v;
    // dereference v_ptr and update value
    *v_ptr = 7;
    cout << "v from ptr manipulation is:"<<v <<endl;



    return 0;
}


