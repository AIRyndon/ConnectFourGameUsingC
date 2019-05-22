#include "ColumnChecker.h"

int check_column(Node board[6][7], Node* node)
{
	int count = 0;
	int last_dropped = 1;

	count = check_downward(board, node, count);

	return last_dropped + count;
}

int check_downward(Node board[6][7], Node* node, int count)
{
	Node* row_down = &board[node->row + 1][node->column];

	if ((node->piece == row_down->piece) && (node->row < 5 && count < 3))
	{
		++count;
		return check_downward(board, row_down, count);
	}

	return count;
};

int check_upward(Node board[6][7], Node* node, int count)
{
	Node* row_up = &board[node->row - 1][node->column];

	if ((node->piece == row_up->piece) && (node->row > 0 && count < 3))
	{
		++count;
		return check_upward(board, row_up, count);
	}

	return count;
};