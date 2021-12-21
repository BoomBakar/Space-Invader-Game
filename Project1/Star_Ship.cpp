#include"game.h"

StarShip::StarShip()
{
	this->xaxis = 3;
	this->lives = 1;
}

void StarShip::setx(int x)
{
	this->xaxis = x;
}

void StarShip::sety(int y)
{
	this->yaxis = y;
}

int StarShip::getx()
{
	return this->xaxis;
}

int StarShip::gety()
{
	return this->yaxis;
}

int StarShip::getModal()
{
	return this->SHIP_MODAL;
}

void StarShip::shipMove()
{
	if (xaxis < 25)
	{
		++xaxis;
	}
}

int StarShip::getLives()
{
	return this->lives;
}

void StarShip::setLives(int life)
{
	this->lives = life;
}

void StarShip::lifeMinus()
{
	if (lives > 0)
	{
		--lives;
	}
}


