#include <Core/EntryPoint.h>
#include <Core/Application.h>
#include <Core/Layer.h>

namespace PhysicsSimulation{
	class ExampleLayer : public Layer{
	public:
		ExampleLayer() : Layer("Layer 1"){
		}

		void onAttach() override{
			circle = CreateScope<sf::CircleShape>(50);
		}

		void onDetach() override {}

		void onUpdate(Timestep ts) override{
		}

		void onEvent(sf::Event& event) override {
			if(event.type== sf::Event::KeyPressed){
				if(event.type == sf::Event::Closed) Application::getNativeWindow().close();
				if(event.key.code == sf::Keyboard::Key::Escape){
					Application::getNativeWindow().close();
				}

				switch (event.key.code) {
					case sf::Keyboard::Key::W:
						circle->move(0.0f, -10.f);
						break;
					case sf::Keyboard::Key::A:
						circle->move(-10.f, 0.f);
						break;
					case sf::Keyboard::Key::D:
						circle->move(10.f, 0.f);
						break;
					case sf::Keyboard::Key::S:
						circle->move(0.0f, 10.f);
						break;
					default: break;
				}
			}
		}

		void onRender() override{
			auto& window = Application::getNativeWindow();


			
			circle->setFillColor(sf::Color(100, 250, 50));

			window.draw(*circle);
		}

	private:
		Scope<sf::CircleShape> circle;
	};

	class ExampleLayer2 : public Layer{
	public:

		void onAttach() override{
			triangle = CreateScope<sf::CircleShape>(80, 3);


			// change the size to 100x100
		}

		void onDetach() override{}
		
		void onUpdate(Timestep ts) override{
			
		}

		void onEvent(sf::Event& event) override{
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::T) Application::getNativeWindow().close();
			}
		}

		void onRender() override{
			auto& window = Application::getNativeWindow();

			window.draw(*triangle);
		}
	private:
		Scope<sf::CircleShape> triangle;
	};

	class SandboxApp : public Application{
	public:
		SandboxApp() : Application(){
			/* auto& window = Application::getNativeWindow(); */
			/* window.clear(sf::Color(150, 200, 0)); */
			pushLayer(new ExampleLayer());
			pushLayer(new ExampleLayer2());
		}
	};

	Application* CreateApplication(){
		return new SandboxApp();
	}
};
