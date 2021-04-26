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
#ifndef GVT_COMMON_FREELIST_HH
#define GVT_COMMON_FREELIST_HH

#include <unordered_map>
#include <variant>
#include <functional>

template<typename T>
struct FreeList {
    using T_vec = std::vector<T>;
    T_vec free;
    T_vec used;
    void reserve(int64_t size){
        free.reserve(size);
        used.reserve(size);
    }
};

template<typename ... Ts>
class ObjectPool {
    template<typename T>
    using pool_type = FreeList<T>;
private:
    std::tuple<pool_type<Ts>...> lists;
public:
    template<typename T>
    FreeList<T> &get() {
        return std::get<pool_type<T>>(lists);
    }
};

#endif //GVT_COMMON_FREELIST_HH
