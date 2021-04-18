#ifndef GVT_ORDERID_HH
#define GVT_ORDERID_HH

#include <string>

class OrderID {
public:
    const std::string value;
public:
    explicit OrderID(const std::string& orderID): value{orderID}{};
};

#endif //AMM_ORDERID_HH
