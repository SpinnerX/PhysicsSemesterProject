#include <Core/Application.h>
#include <memory>
#include <Core/Timestep.h>

namespace PhysicsSimulation{
	Application* Application::instance = nullptr;

	Application::Application(const std::string& title){
		window = std::unique_ptr<Window>(Window::create());
		/* window->setCallback(bind_function(this, &Application::onEvent)); */
		instance = this;
	}

	void Application::run(){
		/* window->clear(sf::Color::Green); */

		while(window->isOpen()){
			// Is going to be showing how lonmg this frame current time and the last frame time
			sf::Clock clock;
            float time = (float)clock.getElapsedTime().asSeconds(); // Should be in platform::getTime() (containing impl for Mac, Windows, etc.)
            Timestep timestep = time - lastFrame;

			while(Window::getPolling(event)){
				this->onEvent(event);
			}

			for(Layer* layer : layerStack){
				layer->onUpdate(timestep);
			}

			for(Layer* layer : layerStack){
				layer->onRender();
			}

			window->onUpdate();
		}
	}
	
	void Application::onEvent(sf::Event& e){
		auto iter = layerStack.end();

		while(iter != layerStack.begin()){
			/* if(App.GetEvent(event)){} */
			(*--iter)->onEvent(event);
		}
	}

	void Application::pushLayer(Layer* layer){
        layerStack.pushLayer(layer);
        layer->onAttach();
    }

    void Application::pushOverlay(Layer* layer){
        layerStack.pushOverlay(layer);
        layer->onAttach();
    }
};
