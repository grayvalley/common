/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GVT_COMMON_PRICE_HH
#define GVT_COMMON_PRICE_HH
#include <cstdint>
#include <stdexcept>
namespace GVT {
    struct Price {
        int64_t value;

        Price() : value{0} {};

        explicit Price(int64_t value): value{value}{
            if (value < 0){
                throw std::runtime_error("Price cannot be negative.");
            }
        };
        bool operator==(const Price &other) const { return value == other.value; }
        bool operator <(const Price &other) const { return value < other.value; }
    };
}
namespace std {
    template <>
    struct hash<GVT::Price> {
        size_t operator () (const GVT::Price &s) const {
            using std::hash;
            return hash<int64_t>()(s.value);
        }
    };
}
#endif //GVT_COMMON_PRICE_HH
