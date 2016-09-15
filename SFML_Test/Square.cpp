#include "Constants.h"

#include "Square.h"

Square::Square() : Square(0.0, 0.0) { }

Square::Square(float x, float y) {
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(SQUAREWIDTH, SQUAREWIDTH));
	shape.setFillColor(colourBlue);
}

void Square::Update() {
}

void Square::Draw(sf::RenderWindow& window) {
	if (_on) {
		window.draw(shape);
	}
}

void Square::SetPosition(float x, float y) {
	shape.setPosition(x, y);
}

void Square::SetOn(bool on) {
	_on = on;
}
