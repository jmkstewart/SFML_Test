#pragma once

#include "Square.h"
#include "Tetromino.h"

#include <list>

using namespace std;

class Page {
private:
	// put this on the stack
	// is this pointless?  let's test it out!!!
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
	std::list<sf::Vector2i> _staticSquares;

	void ClearPage();
	void TurnOnTetromino();
	void HandleInput(std::list<sf::Event> events);
	void HandleDrop(sf::Time elapsed);

	bool TetrominoHitBottom(list<sf::Vector2i> activeSquares);
	void DropTetrominoToBottom();
	void TurnOnStaticSquares();
	void HandleCollision();

public:
	Page();
	void update(sf::Time elapsed, std::list<sf::Event> events);
	void draw(sf::RenderWindow& window);
	void AddTetromino();
};
