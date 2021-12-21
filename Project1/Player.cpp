#include"game.h"

Rocket::Rocket()
{
	yloc = COL / 2;
	board[XLOC][yloc] = ROCKET_MODAL;
}

void Rocket::sety(int y)
{
	this->yloc = y;
}


int Rocket::getx()
{
	return this->XLOC;
}

int Rocket::gety()
{
	return this->yloc;
}

int Rocket::getModal()
{
	return this->ROCKET_MODAL;
}

void Rocket::moveLeft()
{
	if (yloc > 2)
	{
		--yloc;
	}
}

void Rocket::moveRight()
{
	if (yloc < COL - 3)
	{
		++yloc;
	}
}
