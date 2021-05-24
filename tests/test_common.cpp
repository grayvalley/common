#include <cmath>
#include <gtest/gtest.h>

#include <grayvalley/common/Price.hh>

TEST(PriceTests, TestRounding) {

   ASSERT_EQ(GVT::dbl_prc_to_i64_prc(std::stod("2393.70"), 2), 239370);
   ASSERT_EQ(GVT::dbl_prc_to_i64_prc(std::stod("2412.74"), 2), 241274);
   ASSERT_EQ(GVT::dbl_prc_to_i64_prc(std::stod("37768.0"), 1), 377680);
   ASSERT_EQ(GVT::dbl_prc_to_i64_prc(std::stod("37768.5"), 1), 377685);
   ASSERT_EQ(GVT::dbl_prc_to_i64_prc(std::stod("1.3352"), 4), 13352);
   ASSERT_EQ(GVT::dbl_prc_to_i64_prc(std::stod("2.0000"), 4), 20000);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}