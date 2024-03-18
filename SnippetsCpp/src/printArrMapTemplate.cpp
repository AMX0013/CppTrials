#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <utility> // For std::pair

// Function to end recursion
void print_end() {
    std::cout << std::endl;
}

// Base case for single non-iterable argument
template<typename T>
typename std::enable_if<!std::is_same<T, std::string>::value && !std::is_same<T, std::vector<bool>>::value, void>::type
print(const T& value) {
    std::cout << value;
}

// Overload for strings to avoid treating them as iterables
void print(const std::string& value) {
    std::cout << "\"" << value << "\"";
}

// Special handling for vector<bool>
void print(const std::vector<bool>& v) {
    std::cout << '{';
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << (v[i] ? "true" : "false");
        if (i != v.size() - 1) std::cout << ", ";
    }
    std::cout << '}';
}

// Recursive variadic template to handle multiple arguments
template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    print(first); // Print the first argument
    ((std::cout << ", ", print(args)), ...); // Fold expression for the rest
    print_end(); // End line after all arguments are printed
}

// Template specialization for pairs
template<typename T1, typename T2>
void print(const std::pair<T1, T2>& p) {
    std::cout << "(";
    print(p.first);
    std::cout << ", ";
    print(p.second);
    std::cout << ")";
}

// Template specialization for vectors
template<typename T>
void print(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        print(vec[i]);
        if (i != vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

// New overload for arrays of vectors
template<typename T>
void print(T* arr, size_t N) {
    std::cout << "[";
    for (size_t i = 0; i < N; ++i) {
        print(arr[i]); // Use existing print for vector
        if (i < N - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}


// Template specialization for maps
template<typename K, typename V>
void print(const std::map<K, V>& map) {
    std::cout << "{";
    for (auto it = map.begin(); it != map.end(); ) {
        print(it->first);
        std::cout << ": ";
        print(it->second);
        ++it;
        if (it != map.end()) std::cout << ", ";
    }
    std::cout << "}";
}


// Specialization for Vectors of Vectors (Multi-Dimensional Vectors)
// This specialization is already covered by our generic std::vector specialization due to its recursive implementation, which can nicely handle multi-dimensional vectors.

// USAGE
int main() {
    // Single-dimensional vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    print(vec);

    // Multi-dimensional vector
    std::vector<std::vector<std::vector<int>>> multiVec = { {{1, 2}, {3, 4}, {5, 6}}, {{11, 21}, {13, 14}, {15, 16}} };
    print(multiVec);

    // Map
    std::map<std::string, int> map = {{"one", 1}, {"two", 2}, {"three", 3}};
    print(map);

    return 0;
}