/*Move Semantics
Move semantics allow us to transfer resources from rvalues (which are about to be destroyed) to another object.
 For example, a vector of market data updates can grow efficiently by moving temporary objects into it rather than copying them.

view : https://cengizhanvarli.medium.com/std-move-and-std-forward-in-c-9237fe0f5d20#:~:text=This%20is%20useful%20in%20situations,to%20another%20without%20unnecessary%20copying.


*/
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// Macro for benchmarking code execution time
#define BENCHMARK(statement) \
    [&]() { \
        auto start = std::chrono::high_resolution_clock::now(); \
        statement; \
        auto end = std::chrono::high_resolution_clock::now(); \
        std::cout << "Execution time: " << \
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() \
        << " microseconds\n"; \
    }()

// `MarketDataUpdate` with both move and copy operations
class MarketDataUpdate {
public:
    std::string securityID;
    double bidPrice;
    double askPrice;
    double lastTradedPrice;
    int volume;

    // Constructor
    MarketDataUpdate(std::string id, double bid, double ask, double lastPrice, int vol)
        : securityID(std::move(id)), bidPrice(bid), askPrice(ask), 
          lastTradedPrice(lastPrice), volume(vol) {}

    // Move constructor
    MarketDataUpdate(MarketDataUpdate&& other) noexcept 
        : securityID(std::move(other.securityID)), bidPrice(other.bidPrice), askPrice(other.askPrice), 
          lastTradedPrice(other.lastTradedPrice), volume(other.volume) {}

    // Copy constructor
    MarketDataUpdate(const MarketDataUpdate& other) 
        : securityID(other.securityID), bidPrice(other.bidPrice), askPrice(other.askPrice), 
          lastTradedPrice(other.lastTradedPrice), volume(other.volume) {}

    // Copy assignment operator
    MarketDataUpdate& operator=(const MarketDataUpdate& other) {
        if (this != &other) {
            securityID = other.securityID;
            bidPrice = other.bidPrice;
            askPrice = other.askPrice;
            lastTradedPrice = other.lastTradedPrice;
            volume = other.volume;
        }
        return *this;
    }
};

int main() {
    // Vector to hold updates
    std::vector<MarketDataUpdate> updates;
    
    // Create a `MarketDataUpdate` object
    MarketDataUpdate update("AAPL", 150.0, 150.5, 150.25, 1000);

    // Benchmark copying
    std::cout << "Copying:\n";
    BENCHMARK(
        for (int i = 0; i < 1000; ++i) {
            updates.push_back(update); // Copy the object
        }
    );

    // Clear the vector to start over
    updates.clear();

    // Benchmark moving
    std::cout << "Moving:\n";
    BENCHMARK(
        for (int i = 0; i < 1000000; ++i) {
            updates.push_back(std::move(update)); // Move the object

            // We need to create a new object because the previous one has been moved from
            update = MarketDataUpdate("AAPL", 150.0, 150.5, 150.25, 1000);
        }
    );

    return 0;
}

/*
In this line, temporaryUpdate is an rvalue, and std::move(temporaryUpdate) casts it to an rvalue reference, 
allowing push_back to use the move constructor of MarketDataUpdate instead of the copy constructor, 
resulting in more efficient resource management. 
        Usually two memory spaces would get allocated  but move only allocates for the new lvalue
*/
