#pragma once
#include "Ball.h"
#include "Framework/GameObject.h"
#include <vector>
#include <cmath>

class BallManager
{
	std::vector<Ball> balls;
	sf::Texture ball_T;
	sf::Vector2u baseWindowSize = sf::Vector2u(1000, 500);
	sf::Vector2u* windowSize = &baseWindowSize;
	int ballSize = 100;

public:
	BallManager();
	BallManager(sf::Vector2u* windowSize);
	~BallManager();
	void initialise(GameObject* object);
	void spawn();
	void spawn(int amount);
	void deathCheck();
	void update(float dt);
	void render(sf::RenderWindow* window);
};

