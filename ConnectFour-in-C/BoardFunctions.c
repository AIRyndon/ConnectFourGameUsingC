#include "BoardFunctions.h"

void check_column(Player player, Node board[6][7], int col)
{
	Piece piece = player ? Cross : Circle;

	for (int row = 5; row >= 0; row--)
	{
		Node* node = &board[row][col];
		if (!node->is_filled)
		{
			fill_node(node, True, piece);
			break;
		}
	}
}

void draw_board(Node* node)
{
	char* pieces[3] = { " - "," O "," X " };
	if (node->column == 0)
	{
		printf("          ");
		printf("%s", pieces[node->piece]);
	}
	else
	{
		printf("%s", pieces[node->piece]);
	}
}

Node* fill_node(Node* node, Bool is_filled, Piece piece)
{
	node->is_filled = is_filled;
	node->piece = piece;

	return node;
}

void loop_through_board(Node board[6][7], fp_loop loop_pointer)
{
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			Node* node = &board[row][col];
			node->row = row;
			node->column = col;
			loop_pointer(node);
		}
		printf("\n");
	}
}

void starting_board(Node* node)
{	
	fill_node(node, False, Blank);
	draw_board(node);
}

void updated_board(Node* node)
{
	draw_board(node);
}