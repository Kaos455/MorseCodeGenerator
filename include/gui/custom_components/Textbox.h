#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

#include "gui/custom_components/ImGuiComponent.h" // Include parent class

namespace ImGuiComponents {
    class Textbox : public ImGuiComponent {
    public:
        // Constructor
        Textbox(const char* label, size_t bufferSize, const ImVec2& size);

        // Destructor
        ~Textbox();

        // Render method for the Textbox
        virtual void render() override;

    private:
        const char* label;         // Label for the Textbox
        size_t bufferSize;         // Size of the input buffer
        char* inputBuffer;
    };
}

#endif // TEXTBOX_H
