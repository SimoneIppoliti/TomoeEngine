#pragma once

#include "TomoeEngine/Layer.h"

#include "TomoeEngine/Events/ApplicationEvent.h"
#include "TomoeEngine/Events/MouseEvent.h"
#include "TomoeEngine/Events/KeyEvent.h"

namespace TomoeEngine {

	class TOMOE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}