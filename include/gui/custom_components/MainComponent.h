#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include "imgui.h"
#include "gui/custom_components/Textbox.h"

class MainComponent
{
public:
	MainComponent();

	void render(); // Render Method

private: 
	ImGuiIO& io;
};

#endif // MAINCOMPONENT_H