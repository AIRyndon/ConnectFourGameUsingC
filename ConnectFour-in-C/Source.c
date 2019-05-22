#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "BoardFunctions.h"
#include "RowChecker.h"
#include "ColumnChecker.h"
#include "DiagonalChecker.h"

int main(void)
{
	printf("This is a Connect 4 game! To win, you must fill either a row,\na column, or a diagonal with your piece.\n\n");
	
	Node board[6][7];
	loop_through_board(board, draw_starting_board);

	int turns = 0;
	int winner = 0;
	PlayerTurn player_turn = Player_1;

	while (!winner && turns < 42)
	{
		++turns;
		int drop_spot = 0;
		Node* node = 0;
		printf("\nWhat column do you want to drop your piece on (0-6)?");
		scanf("%i", &drop_spot);
		system("cls");

		printf("Here is the current board state.\n\n");
		
		node = update_board_state(player_turn, board, drop_spot);
		loop_through_board(board, draw_updated_board);

		if (!winner && turns > 6)
		{
			winner = check_winner(board, node);
		}

		if (!winner)
		{
			player_turn = !player_turn;
		}		
	}

	if (winner)
	{
		printf("\n\nGreat job Player %i!!\n", (player_turn) ? 2 : 1);
	}
	else
	{
		printf("\n\nNo one won this game!!\n");
	}
	
	return 0;
}