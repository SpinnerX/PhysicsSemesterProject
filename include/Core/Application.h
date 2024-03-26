#pragma once
#include <Core/core.h>
#include <Core/Window.h>
#include <string>
#include <Core/LayerStack.h>

namespace PhysicsSimulation{
	class SIM_API Application{
	public:
		Application(const std::string& name = "Physics Simulation");
		
		void run();

		void pushLayer(Layer* layer);
        void pushOverlay(Layer* layer);

		void onEvent(sf::Event& e);

		static Application& Get() { return *instance; }
		static Window& getNativeWindow() { return *instance->window; };

	private:
		static Application* instance;
		Scope<Window> window;
		sf::Event event;
		LayerStack layerStack;
		Timestep lastFrame;
	};
	// To be defined in client.
    Application* CreateApplication();
};
