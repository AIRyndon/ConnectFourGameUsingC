#include "RowChecker.h"

int check_left(Node board[6][7], Node* node, int count)
{
	Node* column_left = &board[node->row][node->column - 1];

	if ((node->piece == column_left->piece) && (node->column > 0 && count < 3))
	{
		++count;
		return check_left(board, column_left, count);
	}

	return count;
}

int check_right(Node board[6][7], Node* node, int count)
{
	Node* column_right = &board[node->row][node->column + 1];

	if ((node->piece == column_right->piece) && (node->column < 6 && count < 3))
	{
		++count;
		return check_right(board, column_right, count);
	}

	return count;
}

int check_row(Node board[6][7], Node* node)
{
	int count_left = 0;
	int count_right = 0;
	int last_dropped = 1;

	count_left = check_left(board, node, count_left);

	if (count_left < 3)
	{
		count_right = check_right(board, node, count_right);
	}

	return last_dropped + count_left + count_right;
}


