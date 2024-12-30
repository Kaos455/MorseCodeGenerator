#ifndef OUTPUTBOX_H
#define OUTPUTBOX_H

#include "imgui.h"
#include <memory>
#include <iostream>

#include "buffer/Buffer.h"
#include "gui/custom_components/ImGuiComponent.h"

namespace ImGuiComponents {
	class OutputBox : public ImGuiComponent
	{
	public:
		OutputBox(const char* label, std::shared_ptr<Buffer> buffer, const ImVec2& size);

		virtual void render() override;


		void applyStyle();
		void popStyle();
	private:
		const char* label;

		ImGuiIO& io;
		std::shared_ptr<Buffer> buffer;
	};
}

#endif // OUTPUTBOX_H