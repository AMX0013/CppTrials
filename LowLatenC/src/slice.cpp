#include <iostream>
#include <vector>

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
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> sliced = slice(v, 2, 5);

    for (int i : sliced) {
        std::cout << i << " ";
    }

    return 0;
}
