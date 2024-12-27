#include "gui/custom_components/Textbox.h"

using namespace ImGuiComponents; 

// Constructor
Textbox::Textbox(const char* label, size_t bufferSize, const ImVec2& size)
    : ImGuiComponent(size), label(label), bufferSize(bufferSize)
{
    inputBuffer = new char[bufferSize];  // Creating a new "static array" dynamically, which is the size of "bufferSize"

    for (int i = 0; i < bufferSize; i++) // Filling the inputBuffer with "null characters" (empty values using the Null termination escape character)
    {
        inputBuffer[i] = '\0';
    }
}

// Destructor
Textbox::~Textbox()
{
    if (inputBuffer) // Check if the object was instanced properly, as if it fails at any point it is not going to delete some "unitialised" values
    {
        delete[] inputBuffer;  // Clearing the inputBuffer
        inputBuffer = nullptr; // Setting the inputBuffer pointer to reference a nullptr 
    }
};

// Render method for the Textbox
void Textbox::render() 
{
     ImGui::InputTextMultiline(label, inputBuffer, bufferSize, getSize());
}