#include <Core/EntryPoint.h>
#include <Core/Application.h>
#include <Core/Layer.h>
#include <Widgets/Button.h>
#include <memory>
#include <Utilities/Math.h>

namespace PhysicsSimulation{
	class ExampleLayer : public Layer{
	public:
		ExampleLayer() : Layer("Layer 1"){
		}

		void onAttach() override{
			//! @note Building our plane when enabling gravity, this is how we may go in approaching it.
			plank = CreateScope<sf::RectangleShape>(sf::Vector2(1000.f, 100.f));
			plank->setPosition(500, 700);
			
			//! @note Building our circle
			circle = CreateScope<sf::CircleShape>(50);
			circlePosition = sf::Vector2f(0.f, 0.f);
			circle->setPosition(500.f, 500.f);
			circle->setFillColor(sf::Color(100, 250, 50));
		}

		void onDetach() override {}

		void onUpdate(Timestep ts) override{
		}

		void onEvent(sf::Event& event) override {
			float rotationSpeed = 0.f;

			if(event.type== sf::Event::KeyPressed){
				if(event.type == sf::Event::Closed) Application::getNativeWindow().close();
				if(event.key.code == sf::Keyboard::Key::Escape){
					Application::getNativeWindow().close();
				}

				/* circle->setPosition(); */
				switch (event.key.code) {
					case sf::Keyboard::Key::W:
						/* circle->move(0.0f, -10.f); */
						rotationEnabled = false;
						circlePosition.x=0.f, circlePosition.y=-speed;
						/* circle->move(0.f, -10.f); */
						break;
					case sf::Keyboard::Key::A:
						/* circle->rotate(10.f); */
						/* circle->move(-10.f, 0.f); */
						rotationEnabled = true;
						rotationSpeed = circleRotateAngle;
						/* circle->rotate(10.f); */
						break;
					case sf::Keyboard::Key::D:
						/* circle->move(10.f, 0.f); */
						rotationEnabled = true;
						rotationSpeed = -circleRotateAngle;
						/* circle->rotate(-10.f); */
						break;
					case sf::Keyboard::Key::S:
						rotationEnabled = false;
						circlePosition.x=0.f, circlePosition.y=speed;
						break;
					default: break;
				}
			}

			if(Utils::intersects(*circle, *plank)){
				coreLogTrace("Circle collided into the plank!");
				/* circle->setPosition(circlePreviousPosition); */
			}

			if(rotationEnabled) circle->rotate(rotationSpeed);
			else circle->move(circlePosition);
			
			//! @note Keeping track of our previous position
			//! @note For collision
			this->circlePreviousPosition = circlePosition;
		}

		void onRender() override{
			/* Application::Get().getNativeWindow().clear(sf::Color(0, 0, 0)); */
			auto& window = Application::getNativeWindow();
			


			window.draw(*circle);

			window.draw(*plank);
		}

	private:
		Scope<sf::CircleShape> circle;
		Scope<sf::RectangleShape> plank; //! @note Our plane to roll the circle.
		Scope<Button> button;
		sf::Vector2f circlePosition;
		bool rotationEnabled = false; // @note For enabling rotation when key event handled
		float circleRotation = 10.f;
		float speed = 10.f; //! @note Threshold for our speed
		float circleRotateAngle = 10.f;
		sf::Vector2f circlePreviousPosition;
	};


	class SandboxApp : public Application{
	public:
		SandboxApp() : Application(){
			/* auto& window = Application::getNativeWindow(); */
			/* window.clear(sf::Color(150, 200, 0)); */
			pushLayer(new ExampleLayer());
			/* pushLayer(new ExampleLayer2()); */
		}
	};

	Application* CreateApplication(){
		return new SandboxApp();
	}
};

