#include <TomoeEngine.h>

class ExampleLayer : public TomoeEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}
	
	void OnUpdate() override
	{
		TOMOE_INFO("ExampleLayer::Update");
	}

	void OnEvent(TomoeEngine::Event& e) override
	{
		TOMOE_TRACE("{}", e.ToString());
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

TomoeEngine::Application* TomoeEngine::CreateApplication() {
	return new Sandbox();
}