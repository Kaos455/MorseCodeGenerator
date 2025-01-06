#include "generator/MorseCodeGenerator.h"

MorseCodeGenerator::MorseCodeGenerator(std::shared_ptr<Buffer<char>> inputBuffer, std::shared_ptr<Buffer<char>> outputBuffer)
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
	int outputCharIndex = 0;

	if (inputData[0] == '\0') {
		m_outputBuffer->clear();
		return;
	}

	for (size_t i = 0; i < m_inputBuffer->getCapacity(); i++)
	{
		if (inputData[i] == '\0' || outputCharIndex > m_outputBuffer->getCapacity())
		{
			break;
		}

		auto morseCodeIterator = morseMap.find(std::tolower(inputData[i]));
		if (morseCodeIterator != morseMap.end())
		{
			MorseCode& morseCode = morseCodeIterator->second;
			for (size_t j = 0; j < morseCode.length; j++)
			{
				if (outputCharIndex > m_outputBuffer->getCapacity())
				{
					break;
				}

				outputData[outputCharIndex] = morseCode.morseCode[j];
				outputCharIndex++;
			}
			outputData[outputCharIndex] = ' ';
			outputCharIndex ++;
		}
		else
		{
			outputData[outputCharIndex] = '#'; // Hash for now signifies an untranslatable character
			outputCharIndex++;

			outputData[outputCharIndex] = ' ';
			outputCharIndex++;
		}
	}
}