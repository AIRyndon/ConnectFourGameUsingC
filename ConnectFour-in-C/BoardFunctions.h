#include <stdio.h>

typedef enum tag_Bool
{
	False,
	True
}Bool;

typedef enum tag_Player_turn
{
	Player_1,
	Player_2
}PlayerTurn;

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

typedef int(*fp_check)(Node board[6][7],Node* node);
typedef Node*(*fp_fill)(Node* node,Bool is_filled, Piece piece);
typedef void(*fp_loop)(Node* node);

int check_column(Node board[6][7], Node* node);
int check_diagonal(Node board[6][7], Node* node);
int check_downward(Node board[6][7], Node* node, int count);
int check_fwdslash_down(Node board[6][7], Node* node, int count);
int check_fwdslash_up(Node board[6][7], Node* node, int count);
int check_left(Node board[6][7], Node* node, int count);
int check_lines(Node board[6][7], Node* node, fp_check check_pointer);
int check_row(Node board[6][7], Node* node);
int check_upward(Node board[6][7], Node* node, int count);
int check_winner(Node board[6][7], Node* node);
Node* fill_node(Node* node, Bool is_filled, Piece piece);
void loop_through_board(Node board[6][7],fp_loop loop_pointer);
void starting_board(Node* node);
Node* update_board_state(PlayerTurn player, Node board[6][7], int col);
void updated_board(Node* node);