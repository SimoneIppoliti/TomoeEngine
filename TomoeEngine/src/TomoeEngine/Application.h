#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace TomoeEngine {
	
	class TOMOE_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// defined in client
	Application* CreateApplication();

}

