#include <Mist.h>

class ExampleLayer : public Mist::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		if (Mist::Input::IsKeyPressed(MT_KEY_TAB))
			MT_INFO("Tab is pressed");
	}


	void OnEvent(Mist::Event& event) override
	{
		//MT_TRACE("ExampleLayerEvent::{0}", event);
	}

};

class Sandbox : public Mist::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());

		PushOverlay(new Mist::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Mist::Application* Mist::CreateApplication()
{
	return new Sandbox();
}