#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <unordered_set>

using Graph = std::vector<std::vector<int>>;

/////////////////////////////////////////////////////////////////////////////////////
// BFS
void bfs(const Graph& graph, int start) {
    std::queue<int> queue;
    std::unordered_set<int> visited;

    queue.push(start);
    visited.insert(start);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();

        std::cout << vertex << " ";

        for (int neighbor : graph[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// DFS Recursive
void dfs_recursive(const Graph& graph, int vertex, std::unordered_set<int>& visited) {
    visited.insert(vertex);
    std::cout << vertex << " ";

    for (int neighbor : graph[vertex]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs_recursive(graph, neighbor, visited);
        }
    }
}

void dfs(const Graph& graph, int start) {
    std::unordered_set<int> visited;
    dfs_recursive(graph, start, visited);
    std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// DFS iterative
void dfs_iterative(const Graph& graph, int start) {
    std::stack<int> stack;
    std::unordered_set<int> visited;

    stack.push(start);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (visited.find(vertex) == visited.end()) {
            std::cout << vertex << " ";
            visited.insert(vertex);

            for (int neighbor : graph[vertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    stack.push(neighbor);
                }
            }
        }
    }

    std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////


// Usage
int main() {
    Graph graph = {
        {1, 2}, // 0
        {0, 3, 4}, // 1
        {0, 4}, // 2
        {1, 5}, // 3
        {1, 2}, // 4
        {3} // 5
    };

    std::cout << "BFS starting from node 0:\n";
    bfs(graph, 0);

    std::cout << "DFS (recursive) starting from node 0:\n";
    dfs(graph, 0);

    std::cout << "DFS (iterative) starting from node 0:\n";
    dfs_iterative(graph, 0);

    return 0;
}

