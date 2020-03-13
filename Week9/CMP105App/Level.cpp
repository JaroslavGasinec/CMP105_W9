#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	windowSize = window->getSize();
	ballManager = new BallManager(&windowSize);
	rainManager = new RainManager(&windowSize);
	bulletManager = new BulletManager(&windowSize);
	// initialise game objects
	player = new Player(&windowSize);
	player->setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A)) {
		ballManager->spawn();
	}
	if (input->isKeyDown(sf::Keyboard::S)) {
		ballManager->spawn(1);
	}
	if (input->isKeyDown(sf::Keyboard::D)) {
		rainManager->spawn();
	}
	if (input->isKeyDown(sf::Keyboard::F)) {
		input->setKeyUp(sf::Keyboard::F);
		bulletManager->spawn(player->getPosition(), sf::Vector2f(input->getMouseX(), input->getMouseY()));
	}
	player->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	windowSize = window->getSize();
	ballManager->update(dt);
	rainManager->update(dt);
	bulletManager->update(dt);
	player->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager->render(window);
	rainManager->render(window);
	bulletManager->render(window);
	window->draw(*player);
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