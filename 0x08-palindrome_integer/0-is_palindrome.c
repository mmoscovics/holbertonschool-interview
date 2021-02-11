#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned int
 * is a palindrome or not
 * 
 * @n: number to be checked as palindrome
 * 
 * Return: 1 if n is a palindrome otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long dig = 0, rev = 0, num = n;

	while (n > 0)
	{
		dig = n % 10;
		rev = rev * 10 + dig;
		n /= 10;
	}
	if (num == rev)
		return (1);
	return (0);
}