#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * main -
 * Return: Always 0.
 */
int main(int argc, char *argv[], char **env)
{
	char *program = argv[0];
	char *input;

	while (1 == 1)
	{
		input = get_user_input(program);
		printf("Input: %s", input);

		char *arguments[] = { input, NULL };

		if (execve(input, arguments, env) == -1)
			perror("Error");
	}

	return (0);
}
