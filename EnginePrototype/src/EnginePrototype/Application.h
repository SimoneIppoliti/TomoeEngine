#pragma once

#include "Core.h"

namespace EnginePrototype {
	
	class ENGINE_PROTOTYPE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// defined in client
	Application* CreateApplication();

}

