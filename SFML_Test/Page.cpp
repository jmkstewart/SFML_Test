#include "Page.h"

#include "Constants.h"

// private
void Page::ClearPage() {
	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].SetOn(false);
			//_squares[i][j].SetOn(true);
		}
	}
}

void Page::TurnOnTetromino() {
	list<sf::Vector2i> activeSquares = _activeTetromino.GetActiveSquares();

	for (list<sf::Vector2i>::iterator square = activeSquares.begin(); square != activeSquares.end(); ++square) {
		_squares[square->x][square->y].SetOn(true);
	}
}

void Page::HandleInput(std::list<sf::Event> events) {
	for (list<sf::Event>::iterator event = events.begin(); event != events.end(); ++event) {
		if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Left) {
			_activeTetromino.MoveLeft(_staticSquares);
		} else if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Right) {
			_activeTetromino.MoveRight(_staticSquares);
		} else if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Up) {
			_activeTetromino.Rotate(Tetromino::Rotation::RIGHT, _staticSquares);
		} else if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Down) {
			DropTetrominoToBottom();
		}
	}
}

void Page::HandleDrop(sf::Time elapsed) {
	_timeSinceLastDrop += elapsed;

	if (_timeSinceLastDrop > sf::milliseconds(500)) {
		_activeTetromino.Drop();
		_timeSinceLastDrop = sf::Time();
	}
}

bool Page::TetrominoHitBottom(list<sf::Vector2i> activeSquares) {
	// first check if the tetromino has hit another tetromino
	for (list<sf::Vector2i>::iterator activeSquare = activeSquares.begin(); activeSquare != activeSquares.end(); ++activeSquare) {
		for (list<sf::Vector2i>::iterator staticSquare = _staticSquares.begin(); staticSquare != _staticSquares.end(); ++staticSquare) {
			if (*activeSquare == *staticSquare) {
				return true;
			}
		}
	}

	// second check if the tetromino has hit the bottom
	for (list<sf::Vector2i>::iterator square = activeSquares.begin(); square != activeSquares.end(); ++square) {
		if (square->y >= PAGEHEIGHT) {
			return true;
		}
	}

	return false; // no collisions
}

void Page::DropTetrominoToBottom() {
	while (!TetrominoHitBottom(_activeTetromino.GetActiveSquares())) {
		_activeTetromino.Drop();
	}
}

void Page::TurnOnStaticSquares() {
	for (list<sf::Vector2i>::iterator square = _staticSquares.begin(); square != _staticSquares.end(); ++square) {
		int x = square->x;
		int y = square->y;

		_squares[x][y].SetOn(true);
	}
}

void Page::HandleCollision() {
	if (TetrominoHitBottom(_activeTetromino.GetActiveSquares())) {
		// bump the tetromino up one so it's no longer colliding
		_activeTetromino.MoveUpForCollision();
		list<sf::Vector2i> activeSquares = _activeTetromino.GetActiveSquares();

		// convert the tetromino squares to static squares
		for (list<sf::Vector2i>::iterator square = activeSquares.begin(); square != activeSquares.end(); ++square) {
			_staticSquares.push_back(sf::Vector2i(square->x, square->y));
		}

		// start a new tetromino at the top
		_activeTetromino = Tetromino();
	}
}

// public
Page::Page() {
	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].SetPosition(PAGEOFFSET_X + (i * (SQUAREWIDTH + SPACEBETWEENSQUARES)), PAGEOFFSET_Y + (j * (SQUAREWIDTH + SPACEBETWEENSQUARES)));
		}
	}
}

void Page::update(sf::Time elapsed, std::list<sf::Event> events) {
	ClearPage();

	HandleDrop(elapsed);
	HandleInput(events);
	HandleCollision();

	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].Update();
		}
	}

	TurnOnTetromino();
	TurnOnStaticSquares();
}

void Page::draw(sf::RenderWindow& window) {
	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].Draw(window);
		}
	}
}

void Page::AddTetromino() {
	_timeSinceLastDrop = sf::Time();
	_activeTetromino = Tetromino();

	TurnOnTetromino();
}