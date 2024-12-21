#ifndef FOOTERCOMPONENT_H
#define FOOTERCOMPONENT_H

#include "imgui.h"

class FooterComponent
{
public:
	FooterComponent();

	void render();

private:
	ImGuiIO& io;
};

#endif // FOOTERCOMPONENT_H