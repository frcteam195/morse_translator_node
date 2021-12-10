#include "morse_translator.hpp"

#include <locale>
#include <sstream>

bool translate(morse_translator::MorseTranslator::Request &request, morse_translator::MorseTranslator::Response &response)
{
    ROS_INFO("Translation Request: %s", request.input.c_str());

    std::stringstream translation, translated_word;

    // Split the provided string into a list of words.
    size_t previous_position, current_position = 0;
    std::vector<std::string> words;

    while (request.input.find(' ', previous_position) != std::string::npos)
    {
        current_position = request.input.find(' ', previous_position);
        words.push_back(request.input.substr(previous_position, current_position - previous_position));
        previous_position = current_position + 1;
    }

    words.push_back(request.input.substr(current_position));

    for (std::string word : words)
    {
        translated_word.str("");

        for (int i = 0; i < word.length(); i++)
        {
            auto morse_character_iterator = morse_character_chart.find(std::toupper(word[i]));
            if (morse_character_iterator != morse_character_chart.end())
            {
                translated_word << morse_character_iterator->second;
            }
            else
            {
                ROS_ERROR("String provided to morse translator contains characters not present in the translation chart!");
                response.output = "..-. .- .. .-..";
                return false;
            }

            if (i < word.length() - 1)
            {
                translated_word << " ";
            }
        }

        translation << translated_word.str();

        if (word != words.back())
        {
            translation << " | ";
        }
    }

    response.output = translation.str();
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