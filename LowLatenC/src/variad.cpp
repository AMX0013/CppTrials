#include<iostream>

// Variadic templates are templates that take a variable number of arguments. 
// A typical use case might be a function that can take any number of arguments of any type.

// Here's an example of a function that uses variadic templates to print any number of arguments.

// The "Args" here is a template parameter pack, and "args" is a function parameter pack.
// A parameter pack is a way to represent 0 or more parameters.

// This is the base case for our recursive function. 
// It does nothing, and is needed to end the recursion.
void print() {}

// This is the recursive function that prints the arguments.
// It takes at least one argument (head), and zero or more additional arguments (tail...).
template<typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    // Print the first argument
    std::cout << head << std::endl;

    // Recursively call print() with the remaining arguments.
    // This uses "parameter pack expansion" to expand the "tail" parameter pack.
    // If there are no remaining arguments, this will call the base case.
    print(tail...);
}

int main() {
    // Call our variadic function with different numbers and types of arguments
    print(1, 2, 3); // prints "1", "2", "3"
    print("Hello", "World"); // prints "Hello", "World"
    print(1, "Hello", 2.0, 'a'); // prints "1", "Hello", "2", "a"

    return 0;
}

/*
Templates:
    Templates in C++ are a powerful tool for generic programming. 
    They allow the creation of functions or classes that can operate with generic types.
    This means that a function or a class can be written once and can handle different data types without being rewritten for each one.

Parameter packs:
    Parameter packs are a feature of C++ that allows a function or template to take an arbitrary number of arguments.
    This is useful for creating functions that can handle different numbers and types of arguments without having to write multiple versions of the same function.


*/