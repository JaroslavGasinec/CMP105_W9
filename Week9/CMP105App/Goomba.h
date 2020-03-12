#pragma once
#include "Framework/GameObject.h"
class Goomba :
	public GameObject
{
	float speed;
public:
	Goomba();
	~Goomba();

	void update(float dt) override;
};

