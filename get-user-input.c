#include <stdio.h>
#include "main.h"

/**
 * get_user_input - uses getline to accept user input
 * @s: program name
 * Return: user input
 */
char *get_user_input(char *s)
{
	char *buffer = NULL;
	size_t n = 32;
	size_t length;

	printf("%s: ", s);
	length = getline(&buffer, &n, stdin);
	return (buffer);
}
