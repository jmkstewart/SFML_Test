#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"
#include "Tetromino.h"
#include "Level.h"
#include "GameBox.h"
#include "HUDBox.h"

using namespace std;

class Game : public ILevelListener {
private:
	Level _page = Level(this);
	GameBox _gameBox{};
	HUDBox _hudBox{};
	sf::Clock _clock;
	sf::RenderWindow* _window;

	bool _gameOver = false;

public:
	Game(sf::RenderWindow* window);
	void Run();

	// ILevelListener
	void LevelFailed();
};