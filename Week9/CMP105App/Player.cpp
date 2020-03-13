#include "Player.h"

Player::Player(sf::Vector2u* windowSize)
{
	this->windowSize = windowSize;
	setSize(sf::Vector2f(100, 150));
	setFillColor(sf::Color::Red);
	setPosition(windowSize->x/2, windowSize->y / 2);
}

Player::~Player()
{
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up) && !(getPosition().y <= 0)) {
		velocity += sf::Vector2f(0,-movementSpeed);
	}
	if (input->isKeyDown(sf::Keyboard::Down) && !(getPosition().y >= windowSize->y - getSize().y)) {
		velocity += sf::Vector2f(0, +movementSpeed);
	}
	if (input->isKeyDown(sf::Keyboard::Left) && !(getPosition().x <= 0)) {
		velocity += sf::Vector2f(-movementSpeed,0);
	}
	if (input->isKeyDown(sf::Keyboard::Right) && !(getPosition().x >= windowSize->x - getSize().x)) {
		velocity += sf::Vector2f(movementSpeed, 0);
	}
}

void Player::update(float dt)
{
	move(velocity * dt);
	velocity = sf::Vector2f(0, 0);
}
