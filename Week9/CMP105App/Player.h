#pragma once
#include "Framework/GameObject.h"
class Player :
	public GameObject
{
	float movementSpeed = 100;
	sf::Vector2u* windowSize;

public:
	Player(sf::Vector2u* windowSize);
	~Player();
	void handleInput(float dt) override;
	void update(float dt) override;
};

