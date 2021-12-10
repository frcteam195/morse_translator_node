#include "morse_translator.hpp"

#include <gtest/gtest.h>

TEST(TranslationTest, SimpleRequest)
{
    morse_translator::MorseTranslator::Request request;
    morse_translator::MorseTranslator::Response response;

    request.input = "Cat";
    ASSERT_TRUE(translate(request, response));
    ASSERT_EQ(response.output, "-.-. .- -");
}

TEST(TranslationTest, AdvancedRequest)
{
    morse_translator::MorseTranslator::Request request;
    morse_translator::MorseTranslator::Response response;

    request.input = "WHO ARE WE? 195!";
    ASSERT_TRUE(translate(request, response));
    ASSERT_EQ(response.output, ".-- .... --- | .- .-. . | .-- . ..--.. | .---- ----. ..... -.-.--");
}

TEST(TranslationTest, InvalidRequest)
{
    morse_translator::MorseTranslator::Request request;
    morse_translator::MorseTranslator::Response response;

    request.input = "100% Invalid Request";
    ASSERT_FALSE(translate(request, response));
    ASSERT_EQ(response.output, "..-. .- .. .-..");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    ros::NodeHandle nh;
    return RUN_ALL_TESTS();
}