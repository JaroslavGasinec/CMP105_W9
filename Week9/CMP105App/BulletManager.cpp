#include "BulletManager.h"
BulletManager::BulletManager(sf::Vector2u* windowSize)
{
	this->windowSize = windowSize;
	for (int i = 0; i < 20; i++) {
		Bullet newBullet;
		initialise(&newBullet);
		bullets.push_back(newBullet);
	}
}

BulletManager::~BulletManager()
{
}

void BulletManager::initialise(GameObject* object)
{
	object->setSize(sf::Vector2f(bulletSize, bulletSize));
	object->setAlive(false);
}

void BulletManager::spawn(sf::Vector2f playerPoint, sf::Vector2f endPoint)
{
	bool flag = false;
	Bullet* current;
	for (int i = 0; i < bullets.size() && !flag; i++) {
		if (!bullets[i].isAlive()) {
			flag = true;
			current = &bullets[i];
			current->setPosition(playerPoint.x, playerPoint.y);
			current->setDirection(endPoint);
			current->setAlive(true);
		}
	}
}
	

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].isAlive() && 
			(bullets[i].getPosition().y > windowSize->y ||
			 bullets[i].getPosition().y < 0 - bulletSize ||
			 bullets[i].getPosition().x > windowSize->x ||
			 bullets[i].getPosition().x < 0 - bulletSize))
		{
			bullets[i].setAlive(false);
		}
	}
}

void BulletManager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].isAlive()) {
			GameObject* current = &bullets[i];
			current->update(dt);
		}
	}
	deathCheck();
}

void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].isAlive()) {
			window->draw(bullets[i]);
		}
	}
}
