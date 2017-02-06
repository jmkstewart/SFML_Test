#pragma once

#include <SFML/Graphics.hpp>

class HUDBox {
private:
	sf::RectangleShape _outerBox;
	sf::RectangleShape _innerBox;
	sf::Font _font;
	sf::Text _text;

public:
	HUDBox();
	void Draw(sf::RenderWindow& window);
};
