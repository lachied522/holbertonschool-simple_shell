#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * get_user_input - uses getline to accept user input
 * Return: user input
 */
char **get_user_input()
{
	char *buffer = NULL;
	size_t n = 32;
	size_t length;
	char *token;
	char **arguments = malloc(sizeof(char *) * 32);
	int i = 0;

	length = getline(&buffer, &n, stdin);

	buffer[length - 1] = '\0';

	token = strtok(buffer, " ");

	while (token != NULL)
	{
		arguments[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	return (arguments);
}
