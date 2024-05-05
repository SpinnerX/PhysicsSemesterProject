#pragma once
#include <Core/core.h>
#include <Core/Logger.h>
#include <SFML/Graphics.hpp>
#include <Core/Application.h>

namespace PhysicsSimulation{

	class Button : public sf::RectangleShape{
	public:
		Button(const std::string& title, sf::Vector2f& pos, sf::Vector2f& size) {
			label.setString(title);
			setFillColor(sf::Color(255, 255, 255));
			setSize(size);
			/* setPosition(pos); */
		}

		Button(const std::string& t, const sf::Vector2f& size, int charSize, const sf::Color& bgColor, const sf::Color& textColor){
			label.setString(t);
			// text.setColor(textColor);
			setFillColor(textColor);
			label.setColor(sf::Color::Blue);
			// text.setCharacterSize();

			setSize(size);
			setFillColor(bgColor);  
		}
		
		void setBackColor(const sf::Color& color){
			this->setFillColor(color);
		}

		void setFont(const std::string& filename){
			if(!font.loadFromFile(filename)){
				coreLogError("Could not find filename \"{}\"", filename);
				return;
			}

			label.setFont(font);
		}

		void setPosition (sf::Vector2f pos) {
			setPosition(pos);

			float xPos = (pos.x + getGlobalBounds().width / 2) - (label.getGlobalBounds().width / 2);
			float yPos = (pos.y + getGlobalBounds().height / 2) - (label.getGlobalBounds().height / 2);
			label.setPosition({xPos, yPos});
		}

		bool isButtonHovered(){
			auto& window = Application::getNativeWindow();
			/* float mouseX = sf::Mouse::getPosition(window).x; */
			/* float mouseY = sf::Mouse::getPosition(*window).y; */
			
			float mouseX = sf::Mouse::getPosition().x;
			float mouseY = sf::Mouse::getPosition().y;

			float btnPosX = getPosition().x;
			float btnPosY = getPosition().y;

			float btnxPosWidth = getPosition().x + getLocalBounds().width;
			float btnyPosHeight = getPosition().y + getLocalBounds().height;

			if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
				return true;
			}
			else{
				return false;
			}
		}

	private:
		sf::Font font;
		sf::Text label; // @note Buttons label 
	};
}
