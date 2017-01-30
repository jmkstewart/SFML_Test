#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Game.h"

int WinMain()
{
	sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "SFML Test");
	window.setFramerateLimit(120);

	Game game = Game(&window);
	game.Run();

	return 0;
}