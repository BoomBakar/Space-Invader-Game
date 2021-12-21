#include"game.h"

FireBall::FireBall()
{
	this->x_pos = Rocket::getx() - 2;
	this->y_pos = Rocket::gety();
}

int FireBall::getx()
{
	return this->x_pos;
}

int FireBall::gety()
{
	return this->y_pos;
}

void FireBall::sety(int y)
{
	this->y_pos = y;
}

void FireBall::setx(int x)
{
	this->x_pos = x;
}

int FireBall::getModal()
{
	return this->FIRE_MODAL;
}

void FireBall::moveUp()
{
	if (x_pos > 1)
	{
		--x_pos;
	}
}

