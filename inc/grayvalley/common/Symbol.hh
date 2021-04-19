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
#ifndef COMMON_SYMBOL_HH
#define COMMON_SYMBOL_HH
#include <string>
#include <stdexcept>
namespace GVT {
    class Symbol {
    public:
        int64_t value;
    public:
        explicit Symbol(int64_t symbol): value{symbol}{
            if (symbol < 0) {
                throw std::runtime_error("Symbol invalid.");
            }
        };
        bool operator==(const Symbol &other) const { return value == other.value; }
    };
}
namespace std {
    template <>
    struct hash<GVT::Symbol> {
        size_t operator () (const GVT::Symbol &s) const {
            using std::hash;
            return hash<int64_t>()(s.value);
        }
    };
}
#endif //COMMON_VENUE_HH
