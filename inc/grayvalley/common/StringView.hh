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
#ifndef COMMON_STRINGVIEW_HH
#define COMMON_STRINGVIEW_HH

#include <cstring>

#include <grayvalley/common/Macros.hh>

namespace GVT {
    class StringView {
    public:
        const char* base = nullptr;
        size_t len = 0;
    public:
        PREVENT_COPY(StringView);
        PREVENT_MOVE(StringView);
    public:
        StringView() = default;
    public:
        StringView(const char* base, size_t len);
    public:
        static StringView from(const std::string& str);
        static StringView from(const std::vector<uint8_t>& data);
    };
}
namespace GVT {
    StringView::StringView(const char* base, size_t len) : base{base}, len{len}{
    }
}

namespace GVT {
    StringView StringView::from(const std::string &str) {
        return StringView{str.c_str(), strlen(str.c_str())};
    }
}

namespace GVT {
    StringView StringView::from(const std::vector<uint8_t> &data) {
        return StringView {
                reinterpret_cast<const char*>(&data[0]),
                data.size()
        };
    }
}

#endif //COMMON_STRINGVIEW_HH
