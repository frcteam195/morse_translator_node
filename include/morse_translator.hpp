#ifndef MORSE_TRANSLATOR_HPP
#define MORSE_TRANSLATOR_HPP

#include "ros/ros.h"
#include "morse_translator/MorseTranslator.h"

#include <map>

std::map<char, std::string> morse_character_chart = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'.', ".-.-.-"},
    {',', "--..--"},
    {'?', "..--.."},
    {'=', "-...-"},
    {' ', "|"}};

bool translate(morse_translator::MorseTranslator::Request &request, morse_translator::MorseTranslator::Response &response);

bool verify_alphanumeric(std::string str);

#endif // MORSE_TRANSLATOR_HPP