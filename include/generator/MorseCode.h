// Place where the Morse Code is

// Standard Library Includes
#include <unordered_map>
#include <vector>

/*
* @brief Structure for the Morse Code Object found within MorseMap
* 
* Each instance of MorseCode has a length and character vector. This is not exactly needed as vectors have a length method.
* However there are plans to change the method that i am doing the "Morse Code" 
*/
struct MorseCode
{
	int length;
	std::vector<char> morseCode;
};

// This could be better however this is the most simple implementation!
inline std::unordered_map<char, MorseCode> createMorseCodeMap() {
    return {
        // Alphabet
        {'a', {2, {'.', '-'}}},
        {'b', {4, {'-', '.', '.', '.'}}},
        {'c', {4, {'-', '.', '-', '.'}}},
        {'d', {3, {'-', '.', '.'}}},
        {'e', {1, {'.'}}},
        {'f', {4, {'.', '.', '-', '.'}}},
        {'g', {3, {'-', '-', '.'}}},
        {'h', {4, {'.', '.', '.', '.'}}},
        {'i', {2, {'.', '.'}}},
        {'j', {4, {'.', '-', '-', '-'}}},
        {'k', {3, {'-', '.', '-'}}},
        {'l', {4, {'.', '-', '.', '.'}}},
        {'m', {2, {'-', '-'}}},
        {'n', {2, {'-', '.'}}},
        {'o', {3, {'-', '-', '-'}}},
        {'p', {4, {'.', '-', '-', '.'}}},
        {'q', {4, {'-', '-', '.', '-'}}},
        {'r', {3, {'.', '-', '.'}}},
        {'s', {3, {'.', '.', '.'}}},
        {'t', {1, {'-'}}},
        {'u', {3, {'.', '.', '-'}}},
        {'v', {4, {'.', '.', '.', '-'}}},
        {'w', {3, {'.', '-', '-'}}},
        {'x', {4, {'-', '.', '.', '-'}}},
        {'y', {4, {'-', '.', '-', '-'}}},
        {'z', {4, {'-', '-', '.', '.'}}},

        // Numbers
        {'1', {5, {'.', '-', '-', '-', '-'}}},
        {'2', {5, {'.', '.', '-', '-', '-'}}},
        {'3', {5, {'.', '.', '.', '-', '-'}}},
        {'4', {5, {'.', '.', '.', '.', '-'}}},
        {'5', {5, {'.', '.', '.', '.', '.'}}},
        {'6', {5, {'-', '.', '.', '.', '.'}}},
        {'7', {5, {'-', '-', '.', '.', '.'}}},
        {'8', {5, {'-', '-', '-', '.', '.'}}},
        {'9', {5, {'-', '-', '-', '-', '.'}}},
        {'0', {5, {'-', '-', '-', '-', '-'}}},

        // Special Characters
        {'.', {6, {'.', '-', '.', '-', '.', '-'}}},
        {',', {6, {'-', '-', '.', '.', '-', '-'}}},
        {'?', {6, {'.', '.', '-', '-', '.', '.'}}},
        {'!', {6, {'-', '.', '-', '.', '-', '-'}}},

        // Space
        {' ', {1, {'/'}}},

        // New Line Char
        {'\n', {1, {'\n'}}}
    };
}