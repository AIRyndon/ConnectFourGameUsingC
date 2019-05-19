#include <stdio.h>

typedef enum tag_Bool
{
	False,
	True
}Bool;

typedef enum tag_Player
{
	Player_1,
	Player_2
}Player;

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
	int row;
	int column;
}Node;

typedef Node*(*fp_fill)(Node* node,Bool is_filled, Piece piece);
typedef void(*fp_loop)(Node* node);

void check_column(Player player, Node board[6][7], int col);
Node* fill_node(Node* node, Bool is_filled, Piece piece);
void loop_through_board(Node board[6][7],fp_loop loop_pointer);
void starting_board(Node* node);
void updated_board(Node* node);