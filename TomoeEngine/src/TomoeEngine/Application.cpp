#include "tomoepch.h"
#include "Application.h"

#include "TomoeEngine/Events/ApplicationEvent.h"
#include "TomoeEngine/Log.h"

namespace TomoeEngine {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		TOMOE_TRACE(e);

		while (true);
	}

}