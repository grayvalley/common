#ifndef COMMON_PRICE_HH
#define COMMON_PRICE_HH

#include <cstdint>
#include <stdexcept>

namespace GVT {
    struct Price {
        const int64_t value;
        explicit Price(int64_t value): value{value}{
            if (value < 0){
                throw std::runtime_error("Price cannot be negative.");
            }
        };
    };
}

#endif //COMMON_PRICE_HH
