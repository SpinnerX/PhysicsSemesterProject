#include <Core/Window.h>
#include <cstdint>
#include <SFML/Graphics.hpp>
#include <Core/Logger.h>
using namespace sf;

namespace PhysicsSimulation {
	Window* Window::instance = nullptr;
	Window* Window::create(const WindowProperties& properties){
		coreLogInfo("Initializing window ({} x {})", properties.width, properties.height);
		return new Window(properties);
	}

	Window::Window(const WindowProperties& properties){
		window = CreateRef<sf::RenderWindow>();
		window->create(sf::VideoMode(properties.width, properties.height), properties.title);
		window->setVisible(true);
		instance = this;
	}

	void Window::clear(const sf::Color& color){
		window->clear(color);
	}

	bool Window::getPolling(sf::Event &event){
		return instance->window->pollEvent(event);
	}

	void Window::onUpdate(){
		window->display();
	}
}
