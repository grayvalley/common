#ifndef GVT_ORDERID_HH
#define GVT_ORDERID_HH

#include <string>
#include <stdexcept>

class OrderID {
public:
    const std::string value;
public:
    explicit OrderID(const std::string& orderID): value{orderID}{
        if (orderID.empty()){
            throw std::runtime_error("OrderID invalid.");
        }
    };
};

#endif //AMM_ORDERID_HH
