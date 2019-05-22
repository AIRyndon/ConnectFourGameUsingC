#pragma once
#include "Structures.h"

int check_backward_diagonal(Node board[6][7], Node* node);
int check_backslash_down(Node board[6][7], Node* node, int count);
int check_backslash_up(Node board[6][7], Node* node, int count);

int check_fwd_diagonal(Node board[6][7], Node* node);
int check_fwdslash_down(Node board[6][7], Node* node, int count);
int check_fwdslash_up(Node board[6][7], Node* node, int count);