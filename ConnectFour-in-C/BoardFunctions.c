#include "BoardFunctions.h"

int check_column(Node board[6][7], Node* node)
{
	int count = 0;

	count = check_downward(board, node, count);

	if (count < 4)
	{
		count = check_upward(board, node, count);
	}

	return count;
}

int check_downward(Node board[6][7], Node* node, int count)
{
	Node* row_down = &board[node->row + 1][node->column];

	if ((node->piece == row_down->piece) && (node->row < 5 && count < 4))
	{
		return count + check_downward(board, row_down, count + 1);
	}

	return 1;
};

int check_left(Node board[6][7], Node* node, int count)
{
	Node* row_left = &board[node->row][node->column - 1];

	if ((node->piece == row_left->piece) && (node->column > 0 && count < 4))
	{
		return count + check_left(board, row_left, count + 1);
	}

	return 1;
}

int check_lines(Node board[6][7], Node* node, fp_check check_pointer)
{
	int game_won = 0;
	game_won = check_pointer(board, node);

	if (!game_won)
	{
		game_won = check_pointer(board, node);
	}

	return game_won;
}

int check_right(Node board[6][7], Node* node, int count)
{
	Node* row_right = &board[node->row][node->column + 1];

	if ((node->piece == row_right->piece) && (node->column < 6 && count < 4))
	{
		return count + check_right(board, row_right, count + 1);
	}

	return 1;
}

int check_row(Node board[6][7], Node* node)
{
	int count_left = 0;
	int count_right = 0;

	count_left = check_left(board, node, count_left);

	if (count_left < 4)
	{
		count_right = check_right(board, node, count_right);
	}

	return count_left + count_right;
}

int check_upward(Node board[6][7], Node* node, int count)
{
	Node* row_up = &board[node->row - 1][node->column];

	if ((node->piece == row_up->piece) && (node->row > 0 && count < 4))
	{
		return count + check_upward(board, row_up, count + 1);
	}

	return 1;
};

int check_winner(Node board[6][7], Node* node)
{
	int same_pieces = 0;
	int game_won = 0;

	same_pieces = check_column(board, node);

	if (same_pieces < 4)
	{
		same_pieces = check_row(board, node);
	}


	return game_won;
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

void updated_board(Node* node)
{
	draw_board(node);
}