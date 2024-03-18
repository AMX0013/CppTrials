#include <vector>
#include <iostream>

template<typename T>
std::vector<T> slice(const std::vector<T>& v, int start, int end) {
    // Adjust negative indices
    int n = static_cast<int>(v.size());
    if (start < 0) start = n + start;
    if (end < 0) end = n + end;
    
    // Validate range
    if (start > end) start = end;
    if (start < 0) start = 0;
    if (end > n) end = n;

    std::vector<T> result;
    for (int i = start; i < end; ++i) {
        result.push_back(v[i]);
    }
    return result;
}

// Overload for when only the start index is specified
template<typename T>
std::vector<T> slice(const std::vector<T>& v, int start) {
    return slice(v, start, v.size());
}

// Overload for when neither start nor end is specified
template<typename T>
std::vector<T> slice(const std::vector<T>& v) {
    return slice(v, 0, v.size());
}
