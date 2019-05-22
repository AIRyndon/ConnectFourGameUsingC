#define _CRT_SECURE_NO_WARNINGS
#include "BoardFunctions.h"

int main(void)
{
	printf("This is a Connect 4 game! To win, you must fill either a row,\na column, or a diagonal with your piece.\n\n");
	
	Node board[6][7];
	loop_through_board(board, starting_board);

	int turns = 0;
	int winner = 0;
	PlayerTurn player_turn = Player_1;

	while (!winner && turns < 42)
	{
		++turns;
		int drop_spot = 0;
		Node* node = 0;
		printf("What column do you want to drop your piece? ");
		scanf("%i", &drop_spot);

		node = update_board_state(player_turn, board, drop_spot);
		loop_through_board(board, updated_board);

		player_turn = !player_turn;

		if (!winner && turns > 6)
		{
			winner = check_winner(board, node);
		}
	}

	return 0;
}