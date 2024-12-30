#include "generator/MorseCodeGenerator.h"

MorseCodeGenerator::MorseCodeGenerator(std::shared_ptr<Buffer> inputBuffer, std::shared_ptr<Buffer> outputBuffer)
	: m_inputBuffer(inputBuffer), m_outputBuffer(outputBuffer)
{
	morseMap = createMorseCodeMap();
	std::cout << "Setup: Morse Code Generator Initalised" << std::endl;
}

MorseCodeGenerator::~MorseCodeGenerator()
{
	std::cout << "Closing: Generator Shutdown" << std::endl;
}

void MorseCodeGenerator::generate()
{
	char* inputData = m_inputBuffer->getData();
	char* outputData = m_outputBuffer->getData();

	for (size_t i = 0; i < m_inputBuffer->getCapacity(); i++)
	{
		if (inputData[i] == '\0')
		{
			break;
		}

		auto morseCodeIterator = morseMap.find(inputData[i]);
		if (morseCodeIterator != morseMap.end())
		{
			MorseCode& morseCode = morseCodeIterator->second;
			for (size_t j = 0; j < morseCode.length; j++)
			{
				std::cout << morseCode.morseCode[j];
			}
			std::cout << " ";
		}
		else
		{
			std::cout << "Generator Error: Could not find letter - " << inputData[i] << " - within the Morse Code Map" << std::endl;
		}
	}
	std::cout << std::endl;
}