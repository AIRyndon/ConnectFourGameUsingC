#pragma once
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