#include <stdio.h>

typedef enum tag_Bool
{
	False,
	True
}Bool;

typedef enum tag_Turn
{
	Player_1,
	Player_2
}Turn;

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

typedef Node*(*fp_fill)(Node* node,Bool is_filled, Piece piece);

Node* fill_node(Node* node,Bool is_filled, Piece piece);
void draw_board(Node board[6][7],fp_fill func_pointer);
