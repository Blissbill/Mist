#include <Mist.h>

class ExampleLayer : public Mist::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		// MT_INFO("ExampleLayer::Update");
	}


	void OnEvent(Mist::Event& event) override
	{
		MT_TRACE("ExampleLayerEvent::{0}", event);
	}

};

class Sandbox : public Mist::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Mist::Application* Mist:: CreateApplication()
{
	return new Sandbox();
}