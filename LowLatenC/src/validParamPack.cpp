#include <iostream>

template<typename T>
void print(T t) {
    std::cout << t << " ";
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << " ";
    // recursive call
    print(args...);
}

int main() {
    print(1, 2, 3, "Hello", "World");
    std::cout << std::endl;
    print("Only", "one", "argument");
    std::cout << std::endl;
    return 0;
}
