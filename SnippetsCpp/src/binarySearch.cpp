
// bisect.bisect_right (or bisect.bisect): Finds the insertion point for an item in a list to maintain sorted order, where ties go to the right.
// bisect.bisect_left: Similar, but ties go to the left.
// bisect.insort: Inserts an item into a list in sorted order.
// C++'s Standard Template Library (STL) provides similar functionality with std::upper_bound, std::lower_bound, and std::insert.

#include <iostream>
#include <vector>
#include <algorithm> // For std::lower_bound and std::upper_bound

template<typename Container, typename T>
typename Container::iterator bisect_right(Container& container, const T& value) {
    return std::upper_bound(container.begin(), container.end(), value);
}

template<typename Container, typename T>
typename Container::iterator bisect_left(Container& container, const T& value) {
    return std::lower_bound(container.begin(), container.end(), value);
}

template<typename Container, typename T>
void insort(Container& container, const T& value) {
    container.insert(bisect_right(container, value), value);
}

int main() {
    std::vector<int> data = {1, 2, 4, 4, 5, 7, 9};

    // Use bisect_right to find the insertion point
    auto right_pos = bisect_right(data, 4);
    std::cout << "Bisect right index for '4': " << (right_pos - data.begin()) << std::endl;
    // std::cout << "Bisect right index for '4': " << (*right_pos) << std::endl;
    

    // Use bisect_left to find the insertion point
    auto left_pos = bisect_left(data, 4);
    std::cout << "Bisect left index for '4': " << (left_pos - data.begin()) << std::endl;

    // Use insort to insert '6' into data
    insort(data, 6);
    std::cout << "Data after inserting '6': ";
    for(int n : data) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}