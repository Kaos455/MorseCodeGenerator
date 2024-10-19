#ifndef GUIIMGUI_H
#define GUIIMGUI_H

// Includes for Dear ImGui
#include "imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

// Include for Events
#include "events/EventListener.h"

// Includes for Standard Library
#include <iostream>
#include <memory>

class GuiImGui
{
public:
	GuiImGui(std::shared_ptr<event::EventListener> eventListener);

	void imGuiRender();
private:
	std::shared_ptr<event::EventListener> m_eventListener;
};


#endif // GUIIMGUI_H