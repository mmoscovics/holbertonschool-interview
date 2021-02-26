#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * in given direction
 * @line: points to an array of intergers
 * @size: number of elements in array
 * @direction: direction of slide merge
 * Return: 1 upon success, otherwise 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}
	return (0);
}

/**
 * slide_left - slide and merge array to the left
 * @line: array of integers
 * @size: numbner of elements in array
 */
void slide_left(int *line, size_t size)
{
	int i, j, temp, move, end;

	end = (int) size;
	move = 0;
	for (i = 1; i < end; i++)
		if (line[i] != 0)
		{
			temp = line[i];
			for (j = i - 1; j >= move; j--)
			{
				if (line[j] == temp)
				{
					line[j] += temp;
					line[i] = 0;
					move++;
					break;
				}
				else if (j == move && line[j - 1] != 0 && line[j] == 0)
				{
					line[j] = temp;
					line[i] = 0;
					break;
				}
			}
		}
}

/**
 * slide_right - slide and merge array to the left
 * @line: array of integers
 * @size: numbner of elements in array
 */
void slide_right(int *line, size_t size)
{
	int i, j, temp, move;

	move = size - 1;
	for (i = size - 2; i >= 0; i--)
		if (line[i] != 0)
		{
			temp = line[i];
			for (j = i + 1; j <= move; j++)
			{
				if (line[j] == temp)
				{
					line[j] += temp;
					line[i] = 0;
					move--;
					break;
				}
				else if (j == move && line[j + 1] != 0 && line[j] == 0)
				{
					line[j] = temp;
					line[i] = 0;
					break;
				}
			}
		}
}
