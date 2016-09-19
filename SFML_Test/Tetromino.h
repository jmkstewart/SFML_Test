#pragma once

#include <list>
#include <SFML/Graphics.hpp>

using namespace std;

class TetrominoPosition {
public:
	sf::Vector2i squares[4];

	TetrominoPosition();
	TetrominoPosition(sf::Vector2i position_1, sf::Vector2i position_2, sf::Vector2i position_3, sf::Vector2i position_4);
};

class Tetromino {
private:
	bool CanMoveRight(list<sf::Vector2i> staticSquares);
	bool CanMoveLeft(list<sf::Vector2i> staticSquares);
	bool OffBoard();
	bool CollidesWidthStatic(list<sf::Vector2i> staticSquares);

public:
	enum class Rotation {
		LEFT,
		RIGHT
	};

	sf::Vector2i squares[4]{ sf::Vector2i(), sf::Vector2i(), sf::Vector2i(), sf::Vector2i() };

	TetrominoPosition _activePosition;
	int activePositionIndex = 0;
	TetrominoPosition positions[4]{
		TetrominoPosition(sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3)),
		TetrominoPosition(sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1)),
		TetrominoPosition(sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3)),
		TetrominoPosition(sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1))
	};

	Tetromino();

	void Drop();
	void MoveUpForCollision();
	void MoveLeft();
	void MoveRight();
	void Rotate(Rotation direction, list<sf::Vector2i> staticSquares);
	void MoveRight(list<sf::Vector2i> staticSquares);
	void MoveLeft(list<sf::Vector2i> staticSquares);
	std::list<sf::Vector2i> GetActiveSquares();
};


class Tetromino_Square : public Tetromino {
public:
	Tetromino_Square();
};

class Tetromino_TBlock : public Tetromino {
public:
	Tetromino_TBlock();
};

class Tetromino_RightSnake : public Tetromino {
public:
	Tetromino_RightSnake();
};

class Tetromino_LeftSnake : public Tetromino {
public:
	Tetromino_LeftSnake();
};

class Tetromino_LeftGun : public Tetromino {
public:
	Tetromino_LeftGun();
};

class Tetromino_RightGun : public Tetromino {
public:
	Tetromino_RightGun();
};

class Tetromino_Straight : public Tetromino {
public:
	Tetromino_Straight();
};