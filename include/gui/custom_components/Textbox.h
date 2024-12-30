#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>
#include <memory>

#include "buffer/Buffer.h"
#include "gui/custom_components/ImGuiComponent.h" // Include parent class

namespace ImGuiComponents {
    class Textbox : public ImGuiComponent {
    public:
        // Constructor
        Textbox(const char* label, std::shared_ptr<Buffer> buffer, const ImVec2& size);

        // Destructor
        ~Textbox();

        // Render method for the Textbox
        virtual void render() override;

        void applyStyle();
        void popStyle();

    private:
        const char* label; // Label for the Textbox
        std::shared_ptr<Buffer> buffer; // Instance of Buffer object
    };
}

#endif // TEXTBOX_H
