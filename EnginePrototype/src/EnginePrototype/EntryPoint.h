#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern EnginePrototype::Application* EnginePrototype::CreateApplication();

int main(int argc, char** argv)
{
	EnginePrototype::Log::Init();
	ENGINE_CORE_ERROR("Initialized Log");
	int a = 5;
	ENGINE_FATAL("Hello. Var={0}", a);

	auto app = EnginePrototype::CreateApplication();
	app->Run();
	delete app;
}

#endif