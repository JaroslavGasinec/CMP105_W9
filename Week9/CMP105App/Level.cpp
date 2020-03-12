#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	windowSize = window->getSize();
	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A)) {
		ballManager.spawn();
	}
}

// Update game objects
void Level::update(float dt)
{
	windowSize = window->getSize();
	ballManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 100, 100));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}