// Create a template class 'Trade' that can handle various types of trades
// using namespace std;
#include <iostream>
template <class T>
class Trade {
public:
    // Constructor
    Trade(T value) : value(value) {}

    // Getter for value
    T getValue() const {
        return value;
    }

    // Overloaded function to perform trade
    // This can be customized for different types of trades
    virtual void performTrade() {
        std::cout << "Performing generic trade with value: " << value << std::endl;
    }

protected:
    T value;
};

// Create a subclass 'StockTrade' that inherits from 'Trade'
// This class will override the performTrade function
class StockTrade : public Trade<int> {
public:
    // Constructor
    StockTrade(int value) : Trade(value) {}

    // Overridden function to perform stock trade
    void performTrade() override {
        std::cout << "Performing stock trade with value: " << value << std::endl;
    }
};

// Create a subclass 'ForexTrade' that inherits from 'Trade'
// This class will override the performTrade function
class ForexTrade : public Trade<double> {
public:
    // Constructor
    ForexTrade(double value) : Trade(value) {}

    // Overridden function to perform forex trade
    void performTrade() override {
        std::cout << "Performing forex trade with value: " << value << std::endl;
    }
};

int main() {
    StockTrade st(100);
    st.performTrade();

    ForexTrade ft(200.5);
    ft.performTrade();

    return 0;
}