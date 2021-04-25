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
#ifndef COMMON_ORDER_TYPE_HH
#define COMMON_ORDER_TYPE_HH
#include <stdexcept>
namespace GVT {
    class OrderType {
    public:
        std::string value;
    public:
        explicit OrderType(const std::string& type): value{type}{
            if (type.empty()){
                throw std::runtime_error("OrderType invalid.");
            }
        };
    };
}

#endif //COMMON_VENUE_HH