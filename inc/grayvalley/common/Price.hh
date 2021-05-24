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
#include <cmath>
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
        bool operator!=(const Price &other) const { return value != other.value; }
        bool operator< (const Price &other) const { return value < other.value; }
        bool operator> (const Price &other) const { return value > other.value; }
        bool operator<=(const Price &other) const { return value <= other.value; }
        bool operator>=(const Price &other) const { return value >= other.value; }
        friend GVT::Price operator-(const Price& lhs, const Price& rhs){
            return GVT::Price {lhs.value - rhs.value};
        }
        friend GVT::Price operator+(const Price& lhs, const Price& rhs){
            return GVT::Price {lhs.value + rhs.value};
        }
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

namespace GVT {

    int powers_of_10[5] = {
            1, 10, 100, 1000, 10000
    };

    std::string rmcomma(const std::string& src){
        std::string out(src.size(), '0');
        out.erase(std::remove_copy(
                src.begin(), src.end(), out.begin(),
                '.'), out.end());
        return out;
    }

    int64_t dbl_prc_to_i64_prc(const double value, int decimals){
        auto result = std::round(value * GVT::powers_of_10[decimals]);
        return result;
    }

    int64_t dtoi64(double value, int decimals){
        value *= powers_of_10[decimals];
        return static_cast<int64_t>(value);
    }

    double i64tod(int64_t value, int decimals){
        double dbl_value = value / (double)powers_of_10[decimals];
        return static_cast<double>(dbl_value);
    }



}

#endif //GVT_COMMON_PRICE_HH
