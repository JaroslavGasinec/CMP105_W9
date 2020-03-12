#include "Goomba.h"

Goomba::Goomba()
{
	speed = rand() % 50 + 150;
	velocity = sf::Vector2f(0,speed);
}

Goomba::~Goomba()
{
}

void Goomba::update(float dt)
{
	move(velocity * dt);
}
