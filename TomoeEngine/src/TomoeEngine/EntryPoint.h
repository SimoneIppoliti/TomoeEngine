#pragma once

#ifdef TOMOE_PLATFORM_WINDOWS

extern TomoeEngine::Application* TomoeEngine::CreateApplication();

int main(int argc, char** argv)
{
	TomoeEngine::Log::Init();
	TOMOE_CORE_ERROR("Initialized Log");
	int a = 5;
	TOMOE_FATAL("Hello. Var={}", a);

	auto app = TomoeEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif