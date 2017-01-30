#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"
#include "Tetromino.h"
#include "Level.h"
#include "GameBox.h"

using namespace std;

class Game : public ILevelListener {
private:
	Level _page = Level(this);
	GameBox _gameBox{};
	sf::Clock _clock;
	sf::RenderWindow* _window;

public:
	Game(sf::RenderWindow* window);
	void Run();

	// ILevelListener
	void LevelFailed();
};