#include "DiagonalChecker.h"

int check_backward_diagonal(Node board[6][7], Node* node)
{
	int backslash_up = 0;
	int backslash_down = 0;
	int last_dropped = 1;

	backslash_up = check_backslash_up(board, node, backslash_up);

	if (backslash_up < 3)
	{
		backslash_down = check_backslash_down(board, node, backslash_down);
	}

	return last_dropped + backslash_up + backslash_down;
}

int check_backslash_down(Node board[6][7], Node* node, int count)
{
	Node* diag_down = &board[node->row + 1][node->column + 1];

	if ((node->piece == diag_down->piece) && (node->row < 5 && node->column < 6) && count < 3)
	{
		++count;
		return check_backslash_down(board, diag_down, count);
	}

	return count;
}

int check_backslash_up(Node board[6][7], Node* node, int count)
{
	Node* diag_up = &board[node->row - 1][node->column - 1];

	if ((node->piece == diag_up->piece) && (node->row > 0 && node->column > 0) && count < 3)
	{
		++count;
		return check_backslash_up(board, diag_up, count);
	}

	return count;
}

int check_fwd_diagonal(Node board[6][7], Node* node)
{
	int fwdslash_up = 0;
	int fwdslash_down = 0;
	int last_dropped = 1;

	fwdslash_up = check_fwdslash_up(board, node, fwdslash_up);

	if (fwdslash_up < 3)
	{
		fwdslash_down = check_fwdslash_down(board, node, fwdslash_down);
	}

	return last_dropped + fwdslash_up + fwdslash_down;
}

int check_fwdslash_down(Node board[6][7], Node* node, int count)
{
	Node* diag_down = &board[node->row + 1][node->column - 1];

	if ((node->piece == diag_down->piece) && (node->row < 5 && node->column > 0) && count < 3)
	{
		++count;
		return check_fwdslash_down(board, diag_down, count);
	}

	return count;
}

int check_fwdslash_up(Node board[6][7], Node* node, int count)
{
	Node* diag_up = &board[node->row - 1][node->column + 1];

	if ((node->piece == diag_up->piece) && (node->row > 0 && node->column < 6) && count < 3)
	{
		++count;
		return check_fwdslash_up(board, diag_up, count);
	}

	return count;
}