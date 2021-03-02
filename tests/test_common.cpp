#include <gtest/gtest.h>

#include <grayvalley/common/StringView.hh>

TEST(StringViewTests, TestConstruction) {

    std::string str = "Hello";

    GVT::StringView sv{str.c_str(), str.size()};

    ASSERT_EQ(5, sv.len);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}