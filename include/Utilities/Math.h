#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cmath>

namespace Utils{
	//! @note Reference Link --- https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
	static bool intersects(const sf::CircleShape& circleShape, const sf::RectangleShape& rectShape){
		const sf::Vector2f circle = circleShape.getPosition();
		const sf::Vector2f rect = rectShape.getPosition();
		sf::Vector2f rectDimensions = rectShape.getSize();

		sf::Vector2f circleDistance = sf::Vector2f(0.f, 0.f);
		circleDistance.x = abs(circle.x - rect.x);
		circleDistance.y = abs(circle.y - rect.y);

		if (circleDistance.x > (rectDimensions.x/2 + circleShape.getRadius())) { return false; }
		if (circleDistance.y > (rectDimensions.y/2 + circleShape.getRadius())) { return false; }

		if (circleDistance.x <= (rectDimensions.x/2)) { return true; } 
		if (circleDistance.y <= (rectDimensions.y/2)) { return true; }

		/* float cornerDistance_sq = (circleDistance.x - rect.x/2)^2 + (circleDistance.y - rect.y/2)^2; */
		float distanceSq = std::pow((circleDistance.x - rect.x/2), 2) + std::pow((circleDistance.y - rect.y/2), 2);
		/* return (cornerDistance_sq <= (circle.r^2)); */
		return (distanceSq <= (std::pow(circleShape.getRadius(), 2)));
	}
};
