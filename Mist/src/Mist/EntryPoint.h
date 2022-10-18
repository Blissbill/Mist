#pragma once

#ifdef MT_PLATFORM_WINDOWS

extern Mist::Application* Mist::CreateApplication();

int main(int argc, char** argv)
{
	Mist::Application* app = Mist::CreateApplication();
	app->Run();
	delete app;
}

#endif