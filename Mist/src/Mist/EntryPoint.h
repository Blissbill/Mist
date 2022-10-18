#pragma once

#ifdef MT_PLATFORM_WINDOWS

extern Mist::Application* Mist::CreateApplication();

int main(int argc, char** argv)
{
	Mist::Log::Init();
	MT_CORE_INFO("Initialized core log!");
	MT_INFO("Initialized client log!");

	Mist::Application* app = Mist::CreateApplication();
	app->Run();
	delete app;
}

#endif