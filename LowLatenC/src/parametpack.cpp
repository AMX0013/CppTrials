#include <iostream>
/*
Consider that you want to create a function that can take any number of arguments and print them. 
This is where template parameter pack and function parameter pack come into play. Here's how you might do this:
*/




// This is a variadic template function

//In this code, Args is a template parameter pack
template<typename... Args>
//args is a function parameter pack. 
// They represent any number of arguments of any types.
void print(Args... args) {
    // The sizeof... operator returns the number of arguments
    std::cout << "Number of arguments: " << sizeof...(args) << args << std::endl;
}

int main() {
    print(1, 2, 3, "Hello", "World");
    print("Only", "one", "argument");
    return 0;
}


/*
In this code, Args is a template parameter pack and args is a function parameter pack. They represent any number of arguments of any types.

When you call print(1, 2, 3, "Hello", "World");, the template parameter pack Args is instantiated with the types of the arguments (int, int, int, const char*, const char*) and the function parameter pack args is instantiated with the values of the arguments (1, 2, 3, "Hello", "World").

When you call print("Only", "one", "argument");, Args is instantiated with the types (const char*, const char*, const char*) and args is instantiated with the values ("Only", "one", "argument").

This way, you can have a single function that can take any number of arguments of any types, which makes your code more flexible and reusable.
*/