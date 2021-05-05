#ifndef GVT_NETWORK_UTILS_HH
#define GVT_NETWORK_UTILS_HH

#include <cstdint>
#include <netdb.h>

uint64_t ntohll (uint64_t x) {
    const unsigned t = 1;
    if (*(const unsigned char *)&t) {
        x = ((uint64_t)ntohl(x & 0xffffffffU) << 32)
            | ntohl((uint32_t)(x >> 32));
    }
    return x;
}
#endif //GVT_NETWORK_UTILS_HH
