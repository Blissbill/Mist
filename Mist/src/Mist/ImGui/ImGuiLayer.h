#pragma once

#include "Mist/Core.h"
#include "Mist/Layer.h"

#include "Mist/Events/KeyEvent.h"
#include "Mist/Events/MouseEvent.h"
#include "Mist/Events/ApplicationEvent.h"

namespace Mist
{
	class MIST_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent&e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
	private:
		float m_Time = 0.0f;
	};
}