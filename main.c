#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


void execute(char **arguments, char **env)
{
	pid_t pid = fork();

	if (pid == -1)
		perror("Error");

	if (pid == 0)
	{
		if (execve(arguments[0], arguments, env) == -1)
			perror(arguments[0]);
		exit(1);
	}
	else
		wait(NULL);
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char *argv[], char **env)
{
	char **arguments;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		arguments = get_user_input();
		if (arguments[0] == NULL)
			continue;

		char *command = search_path(arguments[0], env);
		if (command == NULL)
			perror(arguments[0]);
		else
			execute(arguments, env);

		free(arguments);
	}

	return (0);
}
