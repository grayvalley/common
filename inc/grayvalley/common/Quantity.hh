#ifndef COMMON_QUANTITY_HH
#define COMMON_QUANTITY_HH

#include <cstdint>
#include <stdexcept>

namespace GVT {
    struct Quantity {
        const int64_t value;
        explicit Quantity(int64_t value): value{value}{
            if (value < 0){
                throw std::runtime_error("Quantity cannot be negative.");
            }
        };
    };
}

#endif //COMMON_QUANTITY_HH
