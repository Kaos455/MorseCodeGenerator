#ifndef IMGUICOMPONENT_H
#define IMGUICOMPONENT_H

#include "imgui.h"

namespace ImGuiComponents 
{
	class ImGuiComponent
	{
	public:
		/**
		 * @brief Abstract Class CustomComponent Constructor. Takes in position and size of the component
		 * 
		 * This constructor will construct the base of any custom component created with the ImGuiComponents namespace
		 * 
		 * @param ImVec2 position - An ImVec2 value to represent position
		 * @param ImVec2 size - An ImVec2 value to represent size
		 */
		ImGuiComponent(const ImVec2& iSize = ImVec2(100.0f, 100.0f), const ImVec2& iPos = ImVec2(100.0f, 0.0f))
		{
			position = iPos;
			size = iSize;
		}

		/**
		 * @brief Default destructor - No dynamic memory, so no reason to define a custom destructor
		 */
		virtual ~ImGuiComponent() = default;

		/*
		* 
		* @brief Pure Virtual function for rendering the ImGui component
		 *
		 * All Components must have a Render method to "render" the component to the window
		 */
		virtual void render() = 0;

		// Getter and Setter for Position and Size of the component
		ImVec2 getPositon() const { return position; }
		void setPosition(const ImVec2& pos) { position = pos; }

		ImVec2 getSize() const { return size; }
		void setSize(const ImVec2& nSize) { size = nSize; }

	private:
		ImVec2 position; // (X, Y)
		ImVec2 size; // (Width, Height)
	};
}

#endif // IMGUICOMPONENT_H