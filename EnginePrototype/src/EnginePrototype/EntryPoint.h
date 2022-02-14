#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern EnginePrototype::Application* EnginePrototype::CreateApplication();

int main(int argc, char** argv)
{
	auto app = EnginePrototype::CreateApplication();
	app->Run();
	delete app;
}

#endif