#include "morse_translator.hpp"

#include <locale>
#include <sstream>

bool translate(morse_translator::MorseTranslator::Request  &request, morse_translator::MorseTranslator::Response &response)
{
    ROS_INFO("Translation Request: %s", request.input.c_str());
    
    if (verify_alphanumeric(request.input))
    {
        std::stringstream translation;

        for(int i = 0; i < request.input.length(); i++)
        {
           translation << morse_character_chart[std::toupper(request.input[i])];
        }

        response.output = translation.str();
        return true;
    }

    return false;
}

bool verify_alphanumeric(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if(!std::isalnum(str[i]))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "morse_translator");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("morse_translate", translate);
    ROS_INFO("Ready to translate!");
    ros::spin();

    return 0;
}