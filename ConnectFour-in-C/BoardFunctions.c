#include "BoardFunctions.h"
#include "ColumnChecker.h"
#include "RowChecker.h"
#include "DiagonalChecker.h"

int check_winner(Node board[6][7], Node* node)
{
	int connect_four = 0;
	int game_won = 0;

	connect_four = check_column(board, node);

	if (connect_four < 4)
	{
		connect_four = check_row(board, node);
	}

	if (connect_four < 4)
	{
		connect_four = check_fwd_diagonal(board, node);
	}

	if (connect_four < 4)
	{
		connect_four = check_backward_diagonal(board, node);
	}

	game_won = connect_four == 4 ? 1 : 0;

	return game_won;
}

void draw_board_pieces(Node* node)
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

void draw_starting_board(Node* node)
{
	fill_node(node, False, Blank);
	draw_board_pieces(node);
}

void draw_updated_board(Node* node)
{
	draw_board_pieces(node);
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

Node* update_board_state(PlayerTurn player, Node board[6][7], int col)
{
	Piece piece = player ? Cross : Circle;
	Node* node = 0;

	for (int row = 5; row >= 0; row--)
	{
		node = &board[row][col];
		if (!node->is_filled)
		{
			fill_node(node, True, piece);
			break;
		}
	}
	return node;
}