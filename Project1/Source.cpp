#include"game.h"


int main()
{
	Game_Manager game;
	char choice;
	game.giveInstructions();
	choice = _getch();
	if (choice == 's')
	{
		game.startGame();
	}
	else
	{
		cout << "\nGame not started";
	}

	return 0;
}