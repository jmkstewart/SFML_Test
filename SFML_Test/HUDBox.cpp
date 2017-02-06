#include "HUDBox.h"

#include "Constants.h"

HUDBox::HUDBox() {
	_outerBox.setPosition(HUDBOXPOSITION_X, HUDBOXPOSITION_Y);
	_innerBox.setPosition(HUDBOXPOSITION_X + HUDBOX_WIDTH, HUDBOXPOSITION_Y + HUDBOX_WIDTH);
	_outerBox.setSize(sf::Vector2f(HUDBOXSIZE_X, HUDBOXSIZE_Y));
	_innerBox.setSize(sf::Vector2f(HUDBOXSIZE_X - (2.0 * HUDBOX_WIDTH), HUDBOXSIZE_Y - (2.0 * HUDBOX_WIDTH)));
	_outerBox.setFillColor(colourOrange);
	_innerBox.setFillColor(colourBlack);

	// Declare and load a font
	if (!_font.loadFromFile("Resources//DejaVuSansMono.ttf")) {
		throw;
	}

	// Create a text
	_text = sf::Text("", _font);
	_text.setCharacterSize(30);
	_text.setStyle(sf::Text::Bold);
	_text.setFillColor(sf::Color::Red);

	_text.setPosition(HUDBOXPOSITION_X + HUDBOX_WIDTH, HUDBOXPOSITION_Y + HUDBOX_WIDTH);
	_text.setString("Lines: 0");
}

void HUDBox::Draw(sf::RenderWindow& window) {
	window.draw(_outerBox);
	window.draw(_innerBox);
	window.draw(_text);
}