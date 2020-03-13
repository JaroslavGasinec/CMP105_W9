#pragma once
#include "Bullet.h"
#include <vector>

class BulletManager
{
	std::vector<Bullet> bullets;
	sf::Vector2u baseWindowSize = sf::Vector2u(1000, 500);
	sf::Vector2u* windowSize = &baseWindowSize;
	int bulletSize = 30;

public:
	BulletManager(sf::Vector2u* windowSize);
	~BulletManager();
	void initialise(GameObject* object);
	void spawn(sf::Vector2f point, sf::Vector2f endPoint);
	void deathCheck();
	void update(float dt);
	void render(sf::RenderWindow* window);
};

