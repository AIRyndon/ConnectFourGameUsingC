#pragma once
#include <stdio.h>
#include "Structures.h"

//typedef int(*fp_check)(Node board[6][7],Node* node);
//typedef Node*(*fp_fill)(Node* node,Bool is_filled, Piece piece);
typedef void(*fp_loop)(Node* node);

int check_winner(Node board[6][7], Node* node);
void draw_board_pieces(Node* node);
void draw_starting_board(Node* node);
void draw_updated_board(Node* node);
Node* fill_node(Node* node, Bool is_filled, Piece piece);
void loop_through_board(Node board[6][7], fp_loop loop_pointer);
Node* update_board_state(PlayerTurn player, Node board[6][7], int col);