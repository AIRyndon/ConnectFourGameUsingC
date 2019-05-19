#include "BoardFunctions.h"


void draw_board(void)
{
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (col == 0)
			{
				printf("          - ");
			}
			else
			{
				printf(" - ");
			}
		}
		printf("\n");
	}
}