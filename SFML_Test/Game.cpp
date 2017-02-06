#include "Game.h"

Game::Game(sf::RenderWindow* window) {
	_window = window;
}

void Game::Run() {

	while (_window->isOpen())
	{
		std::list<sf::Event> events;
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				_window->close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Key::Escape) {
					_window->close();
				} else {
					events.push_back(event);
				}
			}
		}

		_window->clear();

		sf::Time elapsed = _clock.restart();

		_page.update(elapsed, events);

		_gameBox.Draw(*_window);
		_hudBox.Draw(*_window);

		if (!_gameOver) {
			_page.draw(*_window);
		}

		_window->display();

		if (_gameOver) {
			_page = Level(this);
			_gameOver = false;
		}
	}
}

void Game::LevelFailed() {
	_gameOver = true;
}