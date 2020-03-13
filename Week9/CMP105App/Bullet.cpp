#include "Bullet.h"

Bullet::Bullet()
{
	setFillColor(sf::Color::Yellow);
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	move(velocity * dt);
}

void Bullet::setDirection(sf::Vector2f endPoint)
{
	sf::Vector2f direction = endPoint - getPosition();
	direction /= Vector::magnitude(direction);
	velocity = direction * bulletSpeed;
}
