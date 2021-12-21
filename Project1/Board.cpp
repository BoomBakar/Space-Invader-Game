#include"game.h"

Board::Board()
{
	this->board = new char* [this->ROW];
	for (int i = 0; i < ROW; i++)
	{
		this->board[i] = new char[this->COL];
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			this->board[i][j] = ' ';
		}
	}
	this->score = 0;
}

void Board::display()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
			{
				cout << "o";
			}
			else
			{
				cout << this->board[i][j];
			}
		}
		cout << "\n";
	}
	cout << "\n\n\n\nYour Score is: " << this->score;

}

char** Board::getBoard()
{
	return this->board;
}

void Board::setScore(int sc)
{
	this->score = sc;
}

int Board::getScore()
{
	return this->score;
}


