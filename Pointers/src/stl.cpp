#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

int main() {
    // Vector
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4);  // Add element to the end
    vec.pop_back();  // Remove last element
    std::cout << "Vector size: " << vec.size() << std::endl;  // Print size of vector

    // List
    std::list<int> lst = {4, 5, 6};
    lst.push_front(3);  // Add element to the front
    lst.pop_front();  // Remove first element
    std::cout << "List size: " << lst.size() << std::endl;  // Print size of list

    // Set
    std::set<int> st = {7, 8, 9};
    st.insert(10);  // Insert an element
    st.erase(7);  // Erase an element
    std::cout << "Set size: " << st.size() << std::endl;  // Print size of set

    // Map
    std::map<std::string, int> mp = {{"apple", 1}, {"banana", 2}};
    mp["cherry"] = 3;  // Add an element
    mp.erase("apple");  // Remove an element
    std::cout << "Map size: " << mp.size() << std::endl;  // Print size of map

    // Stack
    std::stack<int> s;
    s.push(1);  // Push an element
    s.pop();  // Pop an element
    std::cout << "Stack size: " << s.size() << std::endl;  // Print size of stack

    // Queue
    std::queue<int> q;
    q.push(2);  // Enqueue an element
    q.pop();  // Dequeue an element
    std::cout << "Queue size: " << q.size() << std::endl;  // Print size of queue

    return 0;
}