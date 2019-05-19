#include "BoardFunctions.h"

void draw_board(Node board[6][7])
{
	char* pieces[3] = { " - "," O "," X " };

	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			Node* node = &board[row][col];
			node->is_filled = False;
			node->piece = Blank;

			if (col == 0)
			{
				printf("          ");
				printf("%s", pieces[node->piece]);
			}
			else
			{
				printf("%s",pieces[node->piece]);
			}			
		}
		printf("\n");
	}
}