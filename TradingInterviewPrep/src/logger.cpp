#include <iostream>
#include <utility>

class OrderLogger {
public:
    // Variadic template function that uses fold expressions to log order details
    template<typename... Args>
    static void log(Args&&... args) {
        (std::cout << ... << (OrderLogger::toString(args) + " ")) << std::endl;
    }

private:
    // Convert different types of arguments to a string representation for logging
    // Specialize for different types as needed
    static std::string toString(const char* str) {
        return std::string(str);
    }

    static std::string toString(int value) {
        return std::to_string(value);
    }

    static std::string toString(double value) {
        return std::to_string(value);
    }

    // If you have an 'OrderType' enum, provide a specialized function to convert it to string
    // static std::string toString(OrderType orderType) { /* ... */ }
};

int main() {
    // Example usage of the logger with various types of arguments
    OrderLogger::log("Name","AMXINC","Order Type: Limit", "Quantity:", 100, "Price:", 50.25, "Market Price:", 50.30);
    return 0;
}
