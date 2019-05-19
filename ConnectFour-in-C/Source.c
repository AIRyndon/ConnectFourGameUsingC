#define _CRT_SECURE_NO_WARNINGS
#include "BoardFunctions.h"

int main(void)
{
	printf("This is a Connect 4 game! To win, you must fill either a row,\na column, or a diagonal with your piece.\n\n");
	
	Node board[6][7];
	loop_through_board(board, starting_board);

	int turns = 0;
	int winner = 0;
	Player player_turn = Player_1;

	while (!winner && turns < 42)
	{
		int drop_spot = 0;
		printf("What column do you want to drop your piece? ");
		scanf("%i", &drop_spot);

		check_column(player_turn, board, drop_spot);
		loop_through_board(board, updated_board);
	}

	return 0;
}