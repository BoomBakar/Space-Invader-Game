#include"game.h"

MartianShip::MartianShip()
{
	this->x_axis = 2;
	this->lives = 3;

}

void MartianShip::setx(int x)
{
	this->x_axis = x;
}

void MartianShip::sety(int y)
{
	this->y_axis = y;
}

int MartianShip::getx()
{
	return this->x_axis;
}

int MartianShip::gety()
{
	return y_axis;
}

int MartianShip::getModal()
{
	return this->MARTIAN_MODAL;
}

void MartianShip::shipMove()
{
	if (x_axis < 25)
	{
		++x_axis;
	}
}

int MartianShip::getLives()
{
	return this->lives;
}

void MartianShip::setLives(int life)
{
	this->lives = life;
}

void MartianShip::lifeMinus()
{
	if (lives > 0)
	{
		--lives;
	}
}
