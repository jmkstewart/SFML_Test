#pragma once

#include "Square.h"
#include "Tetromino.h"

#include <list>
#include <random>

using namespace std;

class Level {
private:
	// is it pointless to have this on the stack?  let's test it out!!!
	Square _squares[10][22] = {
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } },
		{ Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } , Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 }, Square{ 0.0, 0.0 } }
	};

	Tetromino _activeTetromino;
	sf::Time _timeSinceLastDrop = sf::Time();
	list<sf::Vector2i> _staticSquares;

	std::mt19937 _rng;
	std::uniform_int_distribution<std::mt19937::result_type> _dist7;

	void ClearLevel();
	void TurnOnTetromino();
	void HandleInput(list<sf::Event> events);
	void HandleDrop(sf::Time elapsed);

	bool TetrominoHitBottom(list<sf::Vector2i> activeSquares);
	void DropTetrominoToBottom();
	void TurnOnStaticSquares();
	void HandleCollision();
	void HandleFullLines();
	void HandleGameOver();
	void UpdateSquares();

	Tetromino GetRandomTetromino();

public:
	Level();
	void update(sf::Time elapsed, std::list<sf::Event> events);
	void draw(sf::RenderWindow& window);
};
