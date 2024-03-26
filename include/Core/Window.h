#pragma once
#include <Core/core.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace PhysicsSimulation{
	struct WindowProperties{
		WindowProperties(const std::string& t="Physics Simulation", uint32_t w = 1600, uint32_t h = 900) : title(t), width(w), height(h) {}

		uint32_t width, height;
		std::string title;
	};
	

	/*
	 * @class Window
	 *
	 * @function isOpen
	 * @note Just allows keep running while this window state is still valid.
	 * @note Just for keeping track of it's state.
	 * 
	 * @function clear()
	 * @note Setting the what color to specify the window to clear too.
	 * @note Essentially refresh default.
	 * @note Takes in a parameter of color, but sets one by default.
	 *
	 *
	 * */
	class SIM_API Window{
		 Window(const WindowProperties& properties);
		 using EventCallbackFn = std::function<void(sf::Event&)>;
	public:
		~Window(){}

		static Window* create(const WindowProperties& properties=WindowProperties());

		bool isOpen() const { return window->isOpen(); }

		static bool getPolling(sf::Event& event);

		static void close() { instance->window->close(); }

		static Ref<sf::RenderWindow> Get() { return instance->window; }

		/*
		 * @function getEvent<EventType>()
		 * @note Should extract the kind of event(key or mouse)
		 * @note Allowing us to tell SFML what key event we would like to check the user is inputting when polling events.
		 *
		 *
		 * API Usage
		 * if(Window::GetEvent<sf::Event::Key>() == sf::Keyboard::Key::Escape){}
		 *
		 * @note Here is more context
		 * -------------------------
		 *  @note The way SFML handles events is you utilize while.inputPoll(event);
		 *  @note So because of the way it handles input polling is interesting... (lol)
		 *  @note Im going to create a better an easier way of setting callbacks
		 *  @note So we can do, window->setEventCallback(callback);
		 *  @note Then we will do, if(Window::GetEvent<Key>() == sf::Keyboard::Key::Escape){}
		 *  @note One thing as to why we are doing this is because we want to allow adding multiple layers.
		 *  @note These rendering layers will represent and contain different components that reside there.
		 *
		 * */
		/* template<typename T> */
		/* T getEvent(); */

		// @function draw<Particle>(particle);
		// @note Idea is in compile time we can draw different specific types of objects.
		/* template<typename T> */
		/* void draw(T& object); */
		/* void draw(); */
		template<typename T>
		void draw(const T& object){
			window->draw(object);
		}

		
		// @note colors set by default.
		void clear(const sf::Color& color);

		void onUpdate();
		
	private:

		static Window* instance;
		Ref<sf::RenderWindow> window;
		sf::Event event;
	};
};
