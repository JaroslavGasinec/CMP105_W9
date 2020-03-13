#include "RainManager.h"
#include <iostream>

RainManager::RainManager(sf::Vector2u* windowSize)
{
	this->windowSize = windowSize;
	goomba_T.loadFromFile("gfx/Goomba.png");
	for (int i = 0; i < 40; i++) {
		Goomba newGoomba;
		initialise(&newGoomba);
		goombas.push_back(newGoomba);
	}
}

RainManager::~RainManager()
{
}

void RainManager::initialise(GameObject* object)
{
	object->setSize(sf::Vector2f(goombaSize, goombaSize));
	object->setTexture(&goomba_T);
	object->setPosition(rand() % (windowSize->x - goombaSize), 0 - goombaSize);
	object->setAlive(false);
}

void RainManager::spawn()
{
	for (int i = 0; i < goombas.size(); i++) {
		goombas[i].setAlive(true);
	}
}

void RainManager::deathCheck()
{
	for (int i = 0; i < goombas.size(); i++) {
		if (goombas[i].isAlive() && goombas[i].getPosition().y > windowSize->y)
		{
			initialise(&goombas[i]);
		}
	}
}

void RainManager::update(float dt)
{
	int out = 0;
	for (int i = 0; i < goombas.size(); i++) {
		if (goombas[i].isAlive()) {
			out++;
			GameObject* current = &goombas[i];
			current->update(dt);
		}
	}
	std::cout << out << std::endl;
	deathCheck();
}

void RainManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < goombas.size(); i++) {
		if (goombas[i].isAlive()) {
			window->draw(goombas[i]);
		}
	}
}
