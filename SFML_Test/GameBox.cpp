#include "GameBox.h"

#include "Constants.h"

GameBox::GameBox() {
	_outerBox.setPosition(GAMEBOXPOSITION_X, GAMEBOXPOSITION_Y);
	_innerBox.setPosition(GAMEBOXPOSITION_X + GAMEBOX_WIDTH, GAMEBOXPOSITION_Y + GAMEBOX_WIDTH);
	_outerBox.setSize(sf::Vector2f(GAMEBOXSIZE_X, GAMEBOXSIZE_Y));
	_innerBox.setSize(sf::Vector2f(GAMEBOXSIZE_X - (2.0 * GAMEBOX_WIDTH), GAMEBOXSIZE_Y - (2.0 * GAMEBOX_WIDTH)));
	_outerBox.setFillColor(colourOrange);
	_innerBox.setFillColor(colourBlack);
}

void GameBox::Draw(sf::RenderWindow& window) {
	window.draw(_outerBox);
	window.draw(_innerBox);
}