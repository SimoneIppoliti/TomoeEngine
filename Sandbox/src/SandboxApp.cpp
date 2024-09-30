#include <TomoeEngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public TomoeEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}
	
	void OnUpdate() override
	{
		//TOMOE_INFO("ExampleLayer::Update");
		if (TomoeEngine::Input::IsKeyPressed(TOMOE_KEY_TAB))
			TOMOE_INFO("Tab key is pressed.");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(TomoeEngine::Event& e) override
	{
		// TOMOE_TRACE("{}", e.ToString());
	}
};

class Sandbox : public TomoeEngine::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

TomoeEngine::Application* TomoeEngine::CreateApplication()
{
	return new Sandbox();
}