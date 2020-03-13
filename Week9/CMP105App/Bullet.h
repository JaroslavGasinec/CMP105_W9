#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Bullet :
	public GameObject
{
	float bulletSpeed = 350;
public:
	Bullet();
	~Bullet();

	void update(float dt) override;
	void setDirection(sf::Vector2f endPoint);
};

