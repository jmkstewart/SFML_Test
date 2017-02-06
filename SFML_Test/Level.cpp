#include "Level.h"

#include "Constants.h"

// private
void Level::ClearLevel() {
	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].SetOn(false);
			//_squares[i][j].SetOn(true);
		}
	}
}

void Level::TurnOnTetromino() {
	list<sf::Vector2i> activeSquares = _activeTetromino.GetActiveSquares();

	for (list<sf::Vector2i>::iterator square = activeSquares.begin(); square != activeSquares.end(); ++square) {
		_squares[square->x][square->y].SetOn(true);
	}
}

void Level::HandleInput(list<sf::Event> events) {
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

void Level::HandleDrop(sf::Time elapsed) {
	_timeSinceLastDrop += elapsed;

	if (_timeSinceLastDrop > sf::milliseconds(500)) {
		_activeTetromino.Drop();
		_timeSinceLastDrop = sf::Time();
	}
}

bool Level::TetrominoHitBottom(list<sf::Vector2i> activeSquares) {
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

void Level::DropTetrominoToBottom() {
	while (!TetrominoHitBottom(_activeTetromino.GetActiveSquares())) {
		_activeTetromino.Drop();
	}
}

void Level::TurnOnStaticSquares() {
	for (list<sf::Vector2i>::iterator square = _staticSquares.begin(); square != _staticSquares.end(); ++square) {
		int x = square->x;
		int y = square->y;

		_squares[x][y].SetOn(true);
	}
}

Tetromino Level::GetRandomTetromino() {
	switch (_dist7(_rng)) {
		case 1:
			return Tetromino_Square();
		case 2:
			return Tetromino_TBlock();
		case 3:
			return Tetromino_RightSnake();
		case 4:
			return Tetromino_LeftSnake();
		case 5:
			return Tetromino_LeftGun();
		case 6:
			return Tetromino_RightGun();
		default:
			return Tetromino_Straight();
	}
}

void Level::HandleCollision() {
	if (TetrominoHitBottom(_activeTetromino.GetActiveSquares())) {
		// bump the tetromino up one so it's no longer colliding
		_activeTetromino.MoveUpForCollision();
		list<sf::Vector2i> activeSquares = _activeTetromino.GetActiveSquares();

		// convert the tetromino squares to static squares
		for (list<sf::Vector2i>::iterator square = activeSquares.begin(); square != activeSquares.end(); ++square) {
			_staticSquares.push_back(sf::Vector2i(square->x, square->y));
		}

		_activeTetromino = GetRandomTetromino();
	}
}

void Level::HandleFullLines() {
	int numberInRow[22];
	for (int i = 0; i < 22; i++) {
		numberInRow[i] = 0;
	}

	for (list<sf::Vector2i>::iterator square = _staticSquares.begin(); square != _staticSquares.end(); ++square) {
		numberInRow[square->y]++;
	}

	for (int i = 0; i < 22; i++) {
		if (numberInRow[i] == 10) {
			// remove the row
			for (int j = 0; j < 10; j++) {
				_staticSquares.remove(sf::Vector2i(j, i));
			}
			// drop all squares above down one
			for (list<sf::Vector2i>::iterator square = _staticSquares.begin(); square != _staticSquares.end(); ++square) {
				if (square->y < i) {
					square->y += 1;
				}
			}
		}
	}
}

void Level::HandleGameOver() {
	// check that all squares are within the game box
	for (list<sf::Vector2i>::iterator square = _staticSquares.begin(); square != _staticSquares.end(); ++square) {
		if (square->y <= 0) {
			_listener->LevelFailed();
			break;
		}
	}
}


// public
Level::Level(ILevelListener *listener) {
	_listener = listener;

	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].SetPosition(PAGEOFFSET_X + (i * (SQUAREWIDTH + SPACEBETWEENSQUARES)), PAGEOFFSET_Y + (j * (SQUAREWIDTH + SPACEBETWEENSQUARES)));
		}
	}

	_rng.seed(std::random_device()());
	_dist7 = std::uniform_int_distribution<std::mt19937::result_type>(1, 7);

	_activeTetromino = GetRandomTetromino();
}

void Level::update(sf::Time elapsed, list<sf::Event> events) {
	ClearLevel();

	HandleDrop(elapsed);
	HandleInput(events);
	HandleCollision();
	HandleFullLines();
	HandleGameOver();

	UpdateSquares();

	TurnOnTetromino();
	TurnOnStaticSquares();
}

void Level::UpdateSquares() {
	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].Update();
		}
	}
}

void Level::draw(sf::RenderWindow& window) {
	for (int i = 0; i < PAGEWIDTH; i++) {
		for (int j = 0; j < PAGEHEIGHT; j++) {
			_squares[i][j].Draw(window);
		}
	}
}
