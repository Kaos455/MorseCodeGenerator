#ifndef MORSECODEGENERATOR_H
#define MORSECODEGENERATOR_H

// Standard Library Includes
#include <iostream>
#include <memory>

// Custom Library Includes
#include "buffer/Buffer.h"
#include "generator/MorseCode.h"

/*
* @brief The MorseCodeGenerator is a class which handles the Morse Code Generation using the MorseMap
* 
* - Handles the generation of Morse Code
* - Requires a Morse Code Map to function properly
* - Requires access to the input and output buffers
*/
class MorseCodeGenerator
{
public:
	/*
	* @brief MorseCodeGenerator constructor handles the instantiation of MorseCodeGenerators
	* @param std::shared_ptr<Buffer<char>> inputBuffer - A Buffer that is of type (char) for Input
	* @param std::shared_ptr<Buffer<char>> outputBuffer - A Buffer that is of type (char) for Output
	* 
	* Allows the Generation of Morse Code based on an Input Buffer into an Output Buffer
	*/
	MorseCodeGenerator(std::shared_ptr<Buffer<char>> inputBuffer, std::shared_ptr<Buffer<char>> outputBuffer);

	/*
	* @brief MorseCodeGenerator destructor handles the destruction of MorseCodeGenerators
	* 
	* Handles any of the future deallocation required, outputs a message to console
	*/
	~MorseCodeGenerator();

	/*
	* @brief Generates Morse Code using the Morse Map based on the inputBuffer and adds it to the Output Buffer
	*/
	void generate();
private:
	std::shared_ptr<Buffer<char>> m_inputBuffer;	// Shared Pointer to input buffer
	std::shared_ptr<Buffer<char>> m_outputBuffer;	// Shared Pointer to output buffer

	std::unordered_map<char, MorseCode> morseMap;
};

#endif // MORSECODEGENERATOR_H