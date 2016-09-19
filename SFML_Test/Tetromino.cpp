#include "Tetromino.h"

TetrominoPosition::TetrominoPosition() {
	squares[0] = sf::Vector2i();
	squares[1] = sf::Vector2i();
	squares[2] = sf::Vector2i();
	squares[3] = sf::Vector2i();
}

TetrominoPosition::TetrominoPosition(sf::Vector2i position_1, sf::Vector2i position_2, sf::Vector2i position_3, sf::Vector2i position_4) {
	squares[0] = position_1;
	squares[1] = position_2;
	squares[2] = position_3;
	squares[3] = position_4;
}


Tetromino_Square::Tetromino_Square() {
	positions[0] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 2), sf::Vector2i(2, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 2), sf::Vector2i(2, 3));
	positions[2] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 2), sf::Vector2i(2, 3));
	positions[3] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 2), sf::Vector2i(2, 3));

	_activePosition = positions[activePositionIndex];
}

Tetromino_TBlock::Tetromino_TBlock() {
	positions[0] = TetrominoPosition(sf::Vector2i(2, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 3), sf::Vector2i(3, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(2, 2), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3));
	positions[2] = TetrominoPosition(sf::Vector2i(2, 2), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1));
	positions[3] = TetrominoPosition(sf::Vector2i(2, 2), sf::Vector2i(3, 1), sf::Vector2i(3, 2), sf::Vector2i(3, 3));

	_activePosition = positions[activePositionIndex];
}

Tetromino_RightSnake::Tetromino_RightSnake() {
	positions[0] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(0, 3), sf::Vector2i(1, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(0, 1), sf::Vector2i(0, 2), sf::Vector2i(1, 2), sf::Vector2i(1, 3));
	positions[2] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(0, 3), sf::Vector2i(1, 3));
	positions[3] = TetrominoPosition(sf::Vector2i(0, 1), sf::Vector2i(0, 2), sf::Vector2i(1, 2), sf::Vector2i(1, 3));

	_activePosition = positions[activePositionIndex];
}

Tetromino_LeftSnake::Tetromino_LeftSnake() {
	positions[0] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(2, 3), sf::Vector2i(3, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 1), sf::Vector2i(2, 2));
	positions[2] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(2, 3), sf::Vector2i(3, 3));
	positions[3] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 1), sf::Vector2i(2, 2));

	_activePosition = positions[activePositionIndex];
}

Tetromino_LeftGun::Tetromino_LeftGun() {
	positions[0] = TetrominoPosition(sf::Vector2i(1, 3), sf::Vector2i(2, 1), sf::Vector2i(2, 2), sf::Vector2i(2, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 3), sf::Vector2i(3, 3));
	positions[2] = TetrominoPosition(sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3));
	positions[3] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2), sf::Vector2i(3, 3));

	_activePosition = positions[activePositionIndex];
}

Tetromino_RightGun::Tetromino_RightGun() {
	positions[0] = TetrominoPosition(sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(2, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2), sf::Vector2i(1, 3));
	positions[2] = TetrominoPosition(sf::Vector2i(2, 1), sf::Vector2i(2, 2), sf::Vector2i(2, 3), sf::Vector2i(1, 1));
	positions[3] = TetrominoPosition(sf::Vector2i(1, 3), sf::Vector2i(2, 3), sf::Vector2i(3, 3), sf::Vector2i(3, 2));

	_activePosition = positions[activePositionIndex];
}

Tetromino_Straight::Tetromino_Straight() {
	positions[0] = TetrominoPosition(sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3));
	positions[1] = TetrominoPosition(sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1));
	positions[2] = TetrominoPosition(sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3));
	positions[3] = TetrominoPosition(sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1));

	_activePosition = positions[activePositionIndex];
}


bool Tetromino::CanMoveRight(list<sf::Vector2i> staticSquares) {
	bool canMoveRight = true;

	MoveRight(); // move our tetromino temporarily

	if (OffBoard() || CollidesWidthStatic(staticSquares)) {
		canMoveRight = false;
	}

	MoveLeft(); // and move it back

	return canMoveRight;
}

bool Tetromino::CanMoveLeft(list<sf::Vector2i> staticSquares) {
	bool canMoveLeft = true;

	MoveLeft(); // move our tetromino temporarily

	if (OffBoard() || CollidesWidthStatic(staticSquares)) {
		canMoveLeft = false;
	}

	MoveRight(); // and move it back

	return canMoveLeft;
}

bool Tetromino::OffBoard() {
	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		if (squares[i].x + _activePosition.squares[i].x == 10) {
			return true;
		} else if (squares[i].x + _activePosition.squares[i].x == -1) {
			return true;
		} else if (squares[i].y + _activePosition.squares[i].y == 22) {
			return true;
		}
	}
	return false;
}

bool Tetromino::CollidesWidthStatic(list<sf::Vector2i> staticSquares) {
	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		for (list<sf::Vector2i>::iterator staticSquare = staticSquares.begin(); staticSquare != staticSquares.end(); ++staticSquare) {
			if (squares[i] + _activePosition.squares[i] == *staticSquare) {
				return true;
			}
		}
	}

	return false;
}


Tetromino::Tetromino() {
	_activePosition = positions[activePositionIndex];
}

void Tetromino::Drop() {
	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		squares[i].y += 1;
	}
}

void Tetromino::MoveUpForCollision() {
	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		squares[i].y -= 1;
	}
}

void Tetromino::MoveLeft() {
	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		squares[i].x -= 1;
	}
}

void Tetromino::MoveRight() {
	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		squares[i].x += 1;
	}
}

void Tetromino::Rotate(Rotation direction, list<sf::Vector2i> staticSquares) {
	int prevPositionIndex = activePositionIndex;

	if (direction == Rotation::RIGHT) {
		activePositionIndex++;
		if (activePositionIndex == 4) {
			activePositionIndex = 0;
		}
		_activePosition = positions[activePositionIndex];
	} else if (direction == Rotation::LEFT) {
		activePositionIndex--;
		if (activePositionIndex == -1) {
			activePositionIndex = 3;
		}
		_activePosition = positions[activePositionIndex];
	}

	if (OffBoard() || CollidesWidthStatic(staticSquares)) {
		activePositionIndex = prevPositionIndex;
		_activePosition = positions[activePositionIndex];
	}
}

void Tetromino::MoveRight(list<sf::Vector2i> staticSquares) {
	if (CanMoveRight(staticSquares)) {
		for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
			squares[i].x += 1;
		}
	}
}

void Tetromino::MoveLeft(list<sf::Vector2i> staticSquares) {
	if (CanMoveLeft(staticSquares)) {
		for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
			squares[i].x -= 1;
		}
	}
}

list<sf::Vector2i> Tetromino::GetActiveSquares() {
	list<sf::Vector2i> activeSquares;

	for (int i = 0; i < sizeof(squares) / sizeof(*squares); i++) {
		activeSquares.push_back(squares[i] + _activePosition.squares[i]);
	}

	return activeSquares;
}
