#include "BallManager.h"

BallManager::BallManager()
{
	srand(time(NULL));
	ball_T.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++) {
		Ball newBall;
		initialise(&newBall);
		balls.push_back(newBall);
	}
}

BallManager::BallManager(sf::Vector2u* windowSize) : BallManager()
{
	delete windowSize;
	this->windowSize = windowSize;
}

BallManager::~BallManager()
{
}

void BallManager::initialise(GameObject* object)
{

	object->setSize(sf::Vector2f(ballSize, ballSize));
	object->setTexture(&ball_T);
	object->setPosition(rand() % (windowSize->x - ballSize), rand() % (windowSize->y - ballSize));
	object->setAlive(false);
}

void BallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++) {
		balls[i].setAlive(true);
	}
}

void BallManager::spawn(int amount)
{
	for (int i = 0; i < balls.size(); i++) {
		if (!balls[i].isAlive() && amount > 0) {
			balls[i].setAlive(true);
			amount--;
		}
	}
	for (int i = amount; i > 0; i--) {
		Ball newBall;
		initialise(&newBall);
		balls.push_back(newBall);
		amount--;
	}
	return;
}

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive() && (
			balls[i].getPosition().x > windowSize->x ||
			balls[i].getPosition().x < 0 - ballSize ||
			balls[i].getPosition().y > windowSize->y ||
			balls[i].getPosition().y < 0 - ballSize))
		{
			initialise(&balls[i]);
		}
	}
}

void BallManager::update(float dt)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			balls[i].update(dt);
		}
	}
	//deathCheck();
}

void BallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			window->draw(balls[i]);
		}
	}
}
