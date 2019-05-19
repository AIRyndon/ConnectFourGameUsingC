#include <stdio.h>

typedef enum tag_Bool
{
	False,
	True
}Bool;

typedef enum tag_Piece
{
	Blank,
	Circle,
	Cross
}Piece;

typedef struct tag_Node
{
	Bool is_filled;
	Piece piece;
}Node;

void draw_board(Node board[6][7]);