#include "BoardFunctions.h"

void draw_board(Node board[6][7],fp_fill fill_node)
{
	char* pieces[3] = { " - "," O "," X " };

	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			Node* node = fill_node(&board[row][col],False,Blank);

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

Node* fill_node(Node* node, Bool is_filled, Piece piece)
{
	node->is_filled = is_filled;
	node->piece = piece;

	return node;
}