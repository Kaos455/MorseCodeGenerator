#ifndef OUTPUTBOX_H
#define OUTPUTBOX_H

// Standard Library Includes
#include <memory>
#include <iostream>

// Dear ImGui Includes
#include "imgui.h"

// Custom Library Includes
#include "buffer/Buffer.h"
#include "gui/custom_components/ImGuiComponent.h"

namespace ImGuiComponents {
	class OutputBox : public ImGuiComponent
	{
	public:
		OutputBox(const char* label, std::shared_ptr<Buffer<char>> buffer, const ImVec2& size);
		~OutputBox();

		virtual void render() override;

		void applyStyle();
		void popStyle();
	private:
		const char* label;

		ImGuiIO& io;
		std::shared_ptr<Buffer<char>> buffer;
	};
}

#endif // OUTPUTBOX_H