#include "morse_translator.hpp"

#include <gtest/gtest.h>

TEST(TranslationTest, Alphanumeric_Verification_Test)
{
    ASSERT_TRUE(verify_alphanumeric("195 Dogs"));
    ASSERT_FALSE(verify_alphanumeric("$195.00 for the #1 Dog"));
}

int test_main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    ros::NodeHandle nh;
    return RUN_ALL_TESTS();
}