#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Mist 
{
	class MIST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}