#include "gui/GuiImGui.h"

// Constructor for ImGui Gui
GuiImGui::GuiImGui(GLFWwindow* window) :
	m_window(window)
{
	if (!initImGui()) {
		std::cerr << "Setup: Failed to initialise ImGui" << std::endl;
	}
}

GuiImGui::~GuiImGui()
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown(); // Shutdown ImGui OpenGL3
	ImGui_ImplGlfw_Shutdown(); // Shutdown ImGui GLFW
	ImGui::DestroyContext(); // Destroy ImGui context
	m_window = nullptr; // Setting the m_window to a nullptr (cannot delete here as it belongs to GuiOpenGL
}

bool GuiImGui::initImGui()
{
	// Code took from looking at the ImGui examples 
	IMGUI_CHECKVERSION(); // Check ImGui version to prevent version mismatch at compile time
	ImGui::CreateContext(); // Create ImGui context
	ImGuiIO& io = ImGui::GetIO(); // Create IO object Reference
	applyTheme();
	setupImGuiFonts(io);

	// Setup ImGui with GLFW and OpenGL3
	if (!ImGui_ImplGlfw_InitForOpenGL(m_window, true)) { // Initialise ImGui with GLFW and tell it to handle events
		std::cerr << "Failed to initialise ImGui with GLFW and OpenGL3" << std::endl;
		return false;
	}
	if (!ImGui_ImplOpenGL3_Init("#version 330")) { // Initialise ImGui with OpenGL3
		std::cerr << "Failed to initialise ImGui with OpenGL3" << std::endl;
		return false;
	}
	std::cout << "Setup: ImGui Initialised" << std::endl;
	return true;
}

// Render Functions
void GuiImGui::preRender() // Pre-render is the where the new frame is added to a buffer
{
	// Start ImGui Frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Make the ImGui window fullscreen and resizable
	ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize));
	ImGui::Begin("Input Test", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);

	static HeaderComponent header;
	header.render();

	ImGui::Separator();

	static MainComponent main;
	main.render();

	ImGui::Separator();

	static FooterComponent footer;
	footer.render();

	ImGui::End();
}

void GuiImGui::render()
{
	ImGui::Render(); // Render ImGui
}

void GuiImGui::postRender()
{
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Render ImGui Draw Data
}

void GuiImGui::applyTheme()
{
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	colors[ImGuiCol_WindowBg] = ImVec4(0.2f, 0.2f, 0.2f, 1.00f);

	style.FrameRounding = 5.0f; // Rounded corners
	style.FramePadding = ImVec2(10, 10); // Padding inside buttons
}

void GuiImGui::setupImGuiFonts(ImGuiIO& io)
{
	// Load Fonts
	ImFont* font1 = io.Fonts->AddFontFromFileTTF("resources/fonts/Roboto-Regular.ttf", 16.0f);
	ImFont* font2 = io.Fonts->AddFontFromFileTTF("resources/fonts/Poppins-Bold.ttf", 48.0f);
	ImFont* font3 = io.Fonts->AddFontFromFileTTF("resources/fonts/Poppins-Regular.ttf", 24.0f);
	ImFont* font4 = io.Fonts->AddFontFromFileTTF("resources/fonts/Poppins-Bold.ttf", 32.0f);

	if (!font1 || !font2 || !font3 || !font4)
	{
		std::cerr << "Failed to Load Font!" << std::endl;
		return;
	}

	io.Fonts->Build();
}