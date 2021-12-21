#include"game.h"

void Game_Manager::startGame()
{
	Rocket p1;
	StarShip s1[10];
	MartianShip s2[5];
	FireBall f1;
	int score = 0;
	resetBoard(s1, s2, p1);
	bool ammo = 1, flag = 1;
	char key_press;

	int i = 0;
	while (true)
	{
		system("CLS");
		br.display();
		Sleep(10);
		if (_kbhit())
		{
			key_press = _getch();
			br.getBoard()[p1.getx()][p1.gety()] = ' ';
			if (key_press == 'a')
			{
				p1.moveLeft();
			}
			else if (key_press == 'd')
			{
				p1.moveRight();
			}
			else if (key_press == 'f')
			{
				if (ammo == 1)
				{
					ammo = 0;
					f1.setx(p1.getx());
					f1.sety(p1.gety());
				}
			}
			br.getBoard()[p1.getx()][p1.gety()] = p1.getModal();
		}
		if (!ammo)
		{
			br.getBoard()[f1.getx()][f1.gety()] = ' ';
			f1.moveUp();
			if (f1.getx() != 1)
			{
				if (br.getBoard()[f1.getx()][f1.gety()] == s1[0].getModal())
				{
					for (int i = 0; i < 10; i++)
					{
						if (f1.getx() == s1[i].getx() && f1.gety() == s1[i].gety())
						{
							s1[i].lifeMinus();
							break;
						}
					}
					ammo = 1;
				}

				else if (br.getBoard()[f1.getx()][f1.gety()] == s2[0].getModal())
				{
					for (int i = 0; i < 5; i++)
					{
						if (f1.getx() == s2[i].getx() && f1.gety() == s2[i].gety())
						{
							s2[i].lifeMinus();
							break;
						}
					}
					ammo = 1;
				}
				else
				{
					br.getBoard()[f1.getx()][f1.gety()] = f1.getModal();
				}
			}
			else
			{
				ammo = 1;
			}
		}
		if (i % 30 == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (s1[i].getLives() > 0)
				{
					br.getBoard()[s1[i].getx()][s1[i].gety()] = ' ';
					s1[i].shipMove();
					br.getBoard()[s1[i].getx()][s1[i].gety()] = s1[i].getModal();
				}
				else
				{
					br.getBoard()[s1[i].getx()][s1[i].gety()] = ' ';
					br.setScore(score + 5);
				}
			}
		}
		if (i % 40 == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				if (s2[i].getLives() > 0)
				{
					br.getBoard()[s2[i].getx()][s2[i].gety()] = ' ';
					s2[i].shipMove();
					br.getBoard()[s2[i].getx()][s2[i].gety()] = s2[i].getModal();
				}
				else
				{
					br.getBoard()[s2[i].getx()][s2[i].gety()] = ' ';
					br.setScore(score + 10);
				}
			}
		}
		for (int i = 2; i < 48; i++)
		{
			if (br.getBoard()[25][i] == s1[0].getModal() || br.getBoard()[25][i] == s2[0].getModal())
			{
				system("CLS");
				cout << "Game Over! Aliens got you!";
				exit(1);
			}
		}
		if (br.getScore() == 100)
		{
			system("CLS");
			cout << "You Won and reached 100 score!";
			exit(1);
		}
		i++;
	}
}

void Game_Manager::resetBoard(StarShip s1[], MartianShip s2[], Rocket& p1)
{
	int temp = 10;
	int position = 15;
	br.getBoard()[p1.getx()][p1.gety()] = p1.getModal();
	for (int i = 0; i < 10; i++, temp += 3)
	{
		s1[i].sety(temp);
	}
	for (int i = 0; i < 10; i++)
	{
		br.getBoard()[s1[i].getx()][s1[i].gety()] = s1[i].getModal();
	}
	for (int i = 0; i < 5; i++, position += 4)
	{
		s2[i].sety(position);
	}
	for (int i = 0; i < 5; i++)
	{
		br.getBoard()[s2[i].getx()][s2[i].gety()] = s2[i].getModal();
	}


}

void Game_Manager::giveInstructions()
{
	cout << "->Welcome to space Invader by Abubakar Dar\n->Following are the Instructions:-\n1-Press 'a' or 'd' to move left and right respectively.\n2-Press 'f' to fire.You only have 1 bullet at 1 time." << endl;
	cout << "3-There are two types of alien ships i.e Martian ships having 3 health bars and Star Ships having 1 health bar(if you destroy a ship and it doesnt disappear then please wait for the loop to iterate. It will disappear!).\n4-Destroy the alien ships before they get close.\nPress 's' to start or any other key to exit.";
}

