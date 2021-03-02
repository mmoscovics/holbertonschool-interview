#include "menger.h"

/**
 * menger - draws a 2d menger sponge
 * @level: level of the sponge to draw
 */
void menger(int level)
{
	int row, row_h, col, col_h, size = pow(3, level);
	char print;

	if (level < 0)
		return;
	for (col = 0; col < size; col++)
	{
		for (row = 0; row < size; row++)
		{
			print = '#';
			row_h = row;
			col_h = col;
			while (row_h > 0 && col_h > 0)
			{
				if (row_h % 3 == 1 && col_h % 3 == 1)
					print = ' ';
				row_h /= 3;
				col_h /= 3;
			}
			printf("%c", print);
		}
		putchar('\n');
	}
}
