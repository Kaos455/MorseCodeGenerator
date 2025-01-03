#ifndef HEADERCOMPONENT_H
#define HEADERCOMPONENT_H

// Standard Library Includes
#include <iostream>

// Dear ImGui Includes
#include "imgui.h"

// Class does not need to inherit from ImGuiComponent due to not needing to encapsulate logic such as an Input Buffer (like Textbox)

/**
 * @brief Header Component class to generate the Header of the GUI
 * 
 * Simple Header integration, abstracted from the Main ImGui render function
 * Takes no parameters
 */
class HeaderComponent {
public:
    HeaderComponent();

    // Render Method
    void render();

    // Component Creation
    void settingButton();
    void titleText();
    void exportButton();

private:
    ImGuiIO& io;

    bool isSettingModalOpen;
    bool isExportModalOpen;
};

#endif // HEADERCOMPONENT_H