/*
A macro in C++ is a fragment of code which is given a name. 
You can define any complex sequence of operations you want as a macro, and then invoke that sequence of operations by calling the macro's name.
Macros are defined using the '#define' directive. Macros are replaced by their definition at compile time. This is often used to 'abstract away' some low-level operations.

Lambda functions are a kind of anonymous function that is used in C++. These functions are not given a name and are defined in the body of the code itself. 
They are useful for creating simple functions, and can be used in the context of function pointers and function objects. 

Lambda functions are defined using the '[]' syntax.

In the provided code, a macro named BENCHMARK is defined that accepts a statement (which can be any valid C++ expression). 
This macro, when invoked, will execute the statement and measure the time it took to execute the statement in microseconds.
 The macro uses a lambda function to encapsulate the timing code and the statement to be timed.
*/
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#define BENCHMARK(statement) \
    [&]() { \
        /* Get the current time before executing the statement */ \
        auto start = std::chrono::high_resolution_clock::now(); \
        /* Execute the statement */ \
        statement; \
        /* Get the current time after executing the statement */ \
        auto end = std::chrono::high_resolution_clock::now(); \
        /* Calculate the duration it took to execute the statement and output it */ \
        std::cout << "Execution time: " << \
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() \
        << " microseconds\n"; \
    }()

int main() {
    std::vector<string>updates;
    std::cout << "Moving:\n";
    BENCHMARK(
        for (int i = 0; i < 1000; ++i) {
            updates.push_back("hello"); // Copy the object
        }
    );
}
