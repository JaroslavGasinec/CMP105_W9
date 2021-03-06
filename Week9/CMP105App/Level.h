#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include <time.h>
#include "BallManager.h"
#include "RainManager.h"
#include "BulletManager.h"
#include "Player.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	sf::Vector2u windowSize;
	BallManager* ballManager;
	RainManager* rainManager;
	BulletManager* bulletManager;
	GameObject* player;
};