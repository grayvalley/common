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
#ifndef GVT_COMMON_SYMBOL_HH
#define GVT_COMMON_SYMBOL_HH
#include <string>
#include <stdexcept>
namespace GVT {
    class Symbol {
    public:
        std::string value;
    public:

        Symbol() = default;

        explicit Symbol(const std::string& symbol): value{symbol}{
            if (symbol.empty()) {
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
            return hash<std::string>()(s.value);
        }
    };
}
#endif //GVT_COMMON_SYMBOL_HH
