#include "Ball.h"
#include <time.h>

Ball::Ball()
{
	int directionX = rand() % 3;
	int directionY = rand() % 3;
	velocity = sf::Vector2f(200*(-1+directionX),200 * (-1 + directionY));
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{
	move(velocity * dt);
}
