#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Square.h"
#include "Tetromino.h"
#include "Page.h"
#include "GameBox.h"

int WinMain()
{
	sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "SFML Test");
	window.setFramerateLimit(120);

	Page page{};
	GameBox gameBox{};
	sf::Clock clock;

	while (window.isOpen())
	{
		std::list<sf::Event> events;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Key::Escape) {
					window.close();
				} else if (event.key.code == sf::Keyboard::Key::A) {
					page.AddTetromino();
				} else {
					events.push_back(event);
				}
			}
		}

		window.clear();

		sf::Time elapsed = clock.restart();

		page.update(elapsed, events);

		gameBox.Draw(window);
		page.draw(window);

		window.display();
	}

	return 0;
}