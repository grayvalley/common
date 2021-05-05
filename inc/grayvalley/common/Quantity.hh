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
#ifndef GVT_COMMON_QUANTITY_HH
#define GVT_COMMON_QUANTITY_HH
#include <cstdint>
#include <stdexcept>
namespace GVT {
    struct Quantity {
        int64_t value;
        Quantity() : value{0} {};
        explicit Quantity(int64_t value): value{value}{
            if (value < 0){
                throw std::runtime_error("Quantity cannot be negative.");
            }
        };
        void set(int64_t new_value){
            value = new_value;
        }
        void set(const Quantity& qty){
            value = qty.value;
        }

        bool operator==(const Quantity &other) const { return value == other.value; }
        bool operator <(const Quantity &other) const { return value < other.value; }

    };
}

#endif //GVT_COMMON_QUANTITY_HH
