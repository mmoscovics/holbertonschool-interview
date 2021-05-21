#include "holberton.h"

/**
 * main - main function to multiply 2 positive numbers
 * @argc: number of arguments passed in
 * @argv: argument value
 * Return: 0 or exit on error
 */
int main(int argc, char *argv[])
{
	unsigned int len1, len2, len3;

	if (argc != 3)
		print_error();

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len3 = len1 + len2;
	string_multiply(argv[1], len1, argv[2], len2, len3);
	return (0);
}

/**
 * _strlen - returns length of string
 * checks if striong only contains numbers
 * @str: passed in string
 * Return: length of string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; ++i)
		if (str[i] < '0' || str[i] > '9')
			print_error();
	return (i);
}

/**
 * print_error - prints error and exit
 */
void print_error(void)
{
	write(1, "Error\n", 6);
	exit(98);
}

/**
 * string_multiply - multiplies 2 strings
 * @str1: First string
 * @len1: Length of first string
 * @str2: Second string
 * @len2: Length of second string
 * @len3: Length to store result string
 * Return: 0 or exit with error
 */

int string_multiply(char *str1, unsigned int len1, char *str2,
		    unsigned int len2, unsigned int len3)
{
	char *r_str;
	int i, j, tmp, num1, num2, result = 0, i1 = 0, j1 = 0;

	r_str = malloc(len3 * sizeof(char));
	if (r_str == NULL)
	{
		free(r_str);
		print_error();
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		tmp = 0;
		num1 = str1[i] - '0';
		i1 = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			num2 = str2[j] - '0';
			result = num1 * num2 + r_str[i1 + j1] + tmp;
			tmp = result / 10;
			r_str[i1 + j1] = result % 10;
			i1++;
		}
		if (tmp > 0)
			r_str[i1 + j1] += tmp;
		j1++;
	}
	i = len3;
	while (i >= 0 && r_str[i] == 0)
		i--;
	if (i < 0)
	{
		write(1, "0\n", 2);
		free(r_str);
		return (0);
	}
	for (; i >= 0; i--)
		_putchar(r_str[i] + '0');
	_putchar('\n');
	free(r_str);
	return (0);
}
