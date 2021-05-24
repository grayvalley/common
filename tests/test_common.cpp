#include <gtest/gtest.h>

#include <grayvalley/common/Price.hh>

TEST(PriceTests, TestRounding) {

    ASSERT_EQ(GVT::s_prc_to_i64_prc("2393.70"), 239370);
    ASSERT_EQ(GVT::s_prc_to_i64_prc("2412.74"), 241274);
    ASSERT_EQ(GVT::s_prc_to_i64_prc("37768.0"), 377680);
    ASSERT_EQ(GVT::s_prc_to_i64_prc("37768.5"), 377685);
    ASSERT_EQ(GVT::s_prc_to_i64_prc("1.3352"), 13352);
    ASSERT_EQ(GVT::s_prc_to_i64_prc("2.0000"), 20000);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}