#define _CRT_SECURE_NO_WARNINGS
#include "BoardFunctions.h"

int main(void)
{
	printf("This is a Connect 4 game! To win, you must fill either a row,\na column, or a diagonal with your piece.\n\n");
	
	Node board[6][7];
	draw_board(board);

	int turns = 0;
	int winner = 0;

	while (!winner && turns < 42)
	{
		int drop_spot = 0;
		printf("What column do you want to drop your piece? ");
		scanf("%i", &drop_spot);
	}

	return 0;
}