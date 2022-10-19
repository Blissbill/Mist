#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Mist 
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MT_CORE_TRACE(e);
		}
		while (true);
	}
}
