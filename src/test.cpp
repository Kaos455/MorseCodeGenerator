#include "buffer/Buffer.h"
#include "generator/MorseCodeGenerator.h"
#include <iostream>
#include <cstring>

// Whilst not the most optimal choice for testing. It does work effectively enough for my purposes. Which is to test different cases
// These cases being.
// Test Input 1,2,3, and 4
// This test is run by making it the "main" function...I know very arbitrary
// All test pass
int test() {
    std::shared_ptr<Buffer<char>> inputBuffer = std::make_shared<Buffer<char>>(512);
    std::shared_ptr<Buffer<char>> outputBuffer = std::make_shared<Buffer<char>>(512);
    MorseCodeGenerator converter(inputBuffer, outputBuffer);

    // Setup some simple tests
    const char* testInput1 = "AB";
    const char* testInput2 = "";
    const char* testInput3 = "Hello I exist";
    const char* testInput4 = "Test with !#.;";

    const char* expectedOutput1 = ".- -... ";
    const char* expectedOutput2 = "";
    const char* expectedOutput3 = ".... . .-.. .-.. --- / .. / . -..- .. ... - ";
    const char* expectedOutput4 = "- . ... - / .-- .. - .... / -.-.-- # .-.-.- # ";

    std::cout << std::endl;


    std::strcpy(inputBuffer->getData(), testInput1);
    converter.generate();
    std::cout << "Input: " << inputBuffer->getData() << std::endl;
    std::cout << "Output: " << outputBuffer->getData() << std::endl;
    if (std::strcmp(outputBuffer->getData(), expectedOutput1) == 0)
    {
        std::cout << "Test 1 Pass!\n" << std::endl;
    }

    std::strcpy(inputBuffer->getData(), testInput2);
    converter.generate();
    std::cout << "Input: " << inputBuffer->getData() << std::endl;
    std::cout << "Output: " << outputBuffer->getData() << std::endl;
    if (std::strcmp(outputBuffer->getData(), expectedOutput2) == 0)
    {
        std::cout << "Test 2 Pass!\n" << std::endl;
    }

    std::strcpy(inputBuffer->getData(), testInput3);
    converter.generate();
    std::cout << "Input: " << inputBuffer->getData() << std::endl;
    std::cout << "Output: " << outputBuffer->getData() << std::endl;
    if (std::strcmp(outputBuffer->getData(), expectedOutput3) == 0)
    {
        std::cout << "Test 3 Pass!\n" << std::endl;
    }

    std::strcpy(inputBuffer->getData(), testInput4);
    converter.generate();
    std::cout << "Input: " << inputBuffer->getData() << std::endl;
    std::cout << "Output: " << outputBuffer->getData() << std::endl;
    if (std::strcmp(outputBuffer->getData(), expectedOutput4) == 0)
    {
        std::cout << "Test 4 Pass!\n" << std::endl;
    }

    return 0;
}
