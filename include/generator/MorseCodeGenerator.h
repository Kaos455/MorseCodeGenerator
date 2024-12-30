#ifndef MORSECODEGENERATOR_H
#define MORSECODEGENERATOR_H
// Morse Code Generator: 
// -> Takes in Input Buffer (somehow, i dont know yet)
// -> Loops through the Input Buffer
//		-> Get 'Character i' of input buffer
//		-> Translate 'Character i' with MorseCode.h associated array
//		-> Add Morse Code to output buffer
// -> Give Output Buffer to GUI (somehow, i dont know yet)

#include <iostream>
#include <memory>
#include "buffer/Buffer.h"
#include "generator/MorseCode.h"

class MorseCodeGenerator
{
public:
	MorseCodeGenerator(std::shared_ptr<Buffer> inputBuffer, std::shared_ptr<Buffer> outputBuffer);
	~MorseCodeGenerator();

	void generate();
private:
	std::shared_ptr<Buffer> m_inputBuffer;
	std::shared_ptr< Buffer> m_outputBuffer;

	std::unordered_map<char, MorseCode> morseMap;
};

#endif // MORSECODEGENERATOR_H