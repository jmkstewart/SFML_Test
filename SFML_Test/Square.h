#pragma once

#include <SFML/Graphics.hpp>

class Square {
private:
	bool _on{ false };

public:
	sf::RectangleShape shape;

	Square();
	Square(float x, float y);

	void Update();
	void Draw(sf::RenderWindow& window);
	void SetPosition(float x, float y);
	void SetOn(bool on);
};
