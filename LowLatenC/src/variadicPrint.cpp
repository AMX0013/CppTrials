#include <iostream>
#include <vector>

// Function to print spaces for indentation
// void printSpaces(int count) {
//     for (int i = 0; i < count; ++i)
//         std::cout <<"";
// }

// Base case: single argument
template<typename T>
void print(const T& t, int indent = 0) {
    // printSpaces(indent);
    std::cout << t ;
}

// Specialization for std::vector
template<typename T>
void print(const std::vector<T>& vec, int indent = 0) {
    // printSpaces(indent);
    std::cout <<"\n" <<"[" ;
    for (const auto& el : vec) {
        // print(el, indent + 2); // recursive call to handle multi-dimensional vectors
        print(el, " "); // recursive call to handle multi-dimensional vectors

    }
    // printSpaces(indent);
    std::cout << "]" << std::endl;
}

// Recursive case: multiple arguments
template<typename T, typename... Args>
void print(const T& t, const Args&... args) {
    print(t);
    print(args...);
}

int main() {
    print(1, "Hello", 3.14, 'a'); // prints 1, Hello, 3.14, a each on a new line
    std::vector<int> vec1 = {1, 2, 3};
    print(vec1); // prints indented vector elements
    std::vector<std::vector<int>> vec2 = {{1, 2}, {3, 4}, {5, 6}};
    print(vec2); // prints indented multi-dimensional vector elements
    return 0;
}
