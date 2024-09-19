#pragma once

#include "Core.h"

#include "Window.h"
#include "TomoeEngine/LayerStack.h"
#include "TomoeEngine/Events/Event.h"
#include "TomoeEngine/Events/ApplicationEvent.h"

namespace TomoeEngine {
	
	class TOMOE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// defined in client
	Application* CreateApplication();

}

