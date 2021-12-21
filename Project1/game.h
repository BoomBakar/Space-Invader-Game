
#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>


using namespace std;

class Board
{
protected:
	const int ROW = 30;
	const int COL = 50;
	char** board;
	int score;
public:
	Board();
	void display();
	char** getBoard();
	void setScore(int);
	int getScore();
};

class SpaceShip : public Board
{
	int xloc;
	int yloc;
public:
	SpaceShip();
	int getxloc();
	int getyloc();
};

class MartianShip :public SpaceShip
{
	int x_axis;
	int y_axis;
	const char MARTIAN_MODAL = char(157);
	int lives;
public:
	MartianShip();
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
	int getModal();
	void shipMove();
	void setLives(int);
	int getLives();
	void lifeMinus();
};

class StarShip :public SpaceShip
{
	int xaxis;
	int yaxis;
	int lives;
	const char SHIP_MODAL = char(239);
public:
	StarShip();
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
	int getModal();
	void shipMove();
	void setLives(int);
	int getLives();
	void lifeMinus();
};

class Rocket : public Board
{
	int yloc;
	const int XLOC = ROW - 3;
	const char ROCKET_MODAL = (char)143;
public:
	Rocket();
	void sety(int y);
	int getx();
	int gety();
	int getModal();
	void moveLeft();
	void moveRight();
};

class FireBall : public Rocket
{
	const char	FIRE_MODAL = char(248);
	int x_pos;
	int y_pos;
public:
	FireBall();
	int getx();
	int gety();
	void setx(int x);
	void sety(int y);
	int getModal();
	void moveUp();
};

class Game_Manager
{
	Board br;
public:
	void startGame();
	void resetBoard(StarShip arr[], MartianShip ar[], Rocket& a);
	void giveInstructions();
};