#pragma once

#include <SFML/Graphics.hpp>

constexpr float SQUAREWIDTH{ 29.0 }, SPACEBETWEENSQUARES{ 1.0 };

constexpr float PAGEOFFSET_X{ 200.0 }, PAGEOFFSET_Y{ 30.0 };

constexpr float GAMEBOXSIZE_X{ 319.0 }, GAMEBOXSIZE_Y{ 679.0 }, GAMEBOX_WIDTH{ 10.0 };
constexpr float GAMEBOXPOSITION_X{ 190.0 }, GAMEBOXPOSITION_Y{ 20.0 };

constexpr float HUDBOXSIZE_X{ 319.0 }, HUDBOXSIZE_Y{ 679.0 }, HUDBOX_WIDTH{ 10.0 };
constexpr float HUDBOXPOSITION_X{ 590.0 }, HUDBOXPOSITION_Y{ 20.0 };

// 720p = 1280, 720
// 1080p = 1920, 1080
constexpr int WINDOWWIDTH{ 1280 }, WINDOWHEIGHT{ 720 };


constexpr int PAGEWIDTH{ 10 }, PAGEHEIGHT{ 22 };

const sf::Color colourBlue = sf::Color(41, 82, 109);
const sf::Color colourOrange = sf::Color(170, 86, 57);
const sf::Color colourBlack = sf::Color::Black;