#define _CRT_SECURE_NO_WARNINGS
#include "BoardFunctions.h"

int main(void)
{
	printf("This is a Connect 4 game! To win, you must fill either a row,\na column, or a diagonal with your piece.\n\n");

	draw_board();

	return 0;
}