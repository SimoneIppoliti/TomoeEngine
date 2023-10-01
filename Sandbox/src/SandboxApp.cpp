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

	void OnEvent(TomoeEngine::Event& event) override
	{
		TOMOE_TRACE("{0}", event);
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