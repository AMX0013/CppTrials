#include <iostream>
#include <vector>

// Base case: single argument
template<typename T>
void print(const T& t) {
    // std::cout << t << std::endl;
    std::cout << t ;

}

// Specialization for std::vector
template<typename T>
void print(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& el : vec) {
        print(el); // recursive call to handle multi-dimensional vectors
        std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Recursive case: multiple arguments
template<typename T, typename... Args>
void print(const T& t, const Args&... args) {
    print(t);
    print(args...);
}

template<typename T>
std::vector<T> slice(const std::vector<T>& v, int start, int end) {
    start = std::max(start, 0);
    end = std::min(end, static_cast<int>(v.size()));

    if (end <= start) {
        return {};
    }

    return std::vector<T>(v.begin() + start, v.begin() + end);
}


int main() {
    print(1, "Hello", 3.14, 'a'); // prints 1, Hello, 3.14, a each on a new line
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    print(vec1); // prints [ 1 2 3 ]
    std::vector<std::vector<int>> vec2 = {{1, 2}, {3, 4}, {5, 6}};
    print(vec2); // prints [ [ 1 2 ] [ 3 4 ] [ 5 6 ] ]

    std::vector<int> sliced = slice(vec1, 2, 5);
    print(sliced);

    return 0;
}
