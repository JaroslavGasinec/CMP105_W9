#pragma once
#include "Goomba.h"
#include <vector>

class RainManager
{
	std::vector<Goomba> goombas;
	sf::Vector2u baseWindowSize = sf::Vector2u(1000, 500);
	sf::Vector2u* windowSize = &baseWindowSize;
	sf::Texture goomba_T;
	int goombaSize = 100;

public:
	RainManager(sf::Vector2u* windowSize);
	~RainManager();
	void initialise(GameObject* object);
	void spawn();
	void deathCheck();
	void update(float dt);
	void render(sf::RenderWindow* window);
};

