#pragma once

#include <SFML/Graphics.hpp>

class GameBox {
private:
	sf::RectangleShape _outerBox;
	sf::RectangleShape _innerBox;

public:
	GameBox();
	void Draw(sf::RenderWindow& window);
};