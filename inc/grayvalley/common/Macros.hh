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
#ifndef GVT_COMMON_MACROS_HH
#define GVT_COMMON_MACROS_HH

#define DELETE_DEFAULT_CTOR(class_name) class_name() = delete;

#define PREVENT_COPY(class_name) class_name(const class_name&) = delete;\
                                 class_name& operator=(const class_name&) = delete

#define PREVENT_MOVE(class_name) class_name(const class_name&&) = delete;\
                                 class_name& operator=(const class_name&&) = delete
#endif //GVT_COMMON_MACROS_HH