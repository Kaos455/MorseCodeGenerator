#ifndef FOOTERCOMPONENT_H
#define FOOTERCOMPONENT_H

// Standard Library Includes
#include <iostream>

// Custom Library Includes
#include "gui/custom_components/MediaPlayer.h"

// Dear ImGui Includes
#include "imgui.h"

/*
 * @brief Footer Component class to generate the Footer of the GUI
 *
 * Simple Footer integration, abstracted from the Main ImGui render function
 * Takes no parameters
*/
class FooterComponent
{
public:
	FooterComponent();

	void render();

private:
	ImGuiIO& io;
};

#endif // FOOTERCOMPONENT_H