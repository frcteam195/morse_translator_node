#include "morse_translator_node/MorseTranslator.h"

#include <gtest/gtest.h>

TEST(TranslationTest, DogTest)
{
    ASSERT_TRUE(1 == 1);
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    ros::NodeHandle nh;
    return RUN_ALL_TESTS();
}