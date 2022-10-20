#pragma once

#include "Mist/Core.h"

#include "Mist/Events/Event.h"
#include "Mist/Events/ApplicationEvent.h"
#include "Mist/Window.h"
#include "Mist/LayerStack.h"

namespace Mist 
{
	class MIST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();

}