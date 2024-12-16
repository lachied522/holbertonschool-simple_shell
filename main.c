#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


void execute(char **arguments, char **env)
{
	char *command;

	if (execve(arguments[0], arguments, env) == -1)
	{
		command = search_path(arguments[0], env);

		if (command == NULL)
			perror("Error");

		arguments[0] = command;
		
		if (execve(arguments[0], arguments, env) == -1)
			perror("Error");
	}
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
	char *program = argv[0];
	char **arguments;
	char *command;
	pid_t pid;

	if (isatty(0) == 1)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
		}
		else if (pid == 0)
		{
			printf("%s: ", program);
			arguments = get_user_input(program);

			execute(arguments, env);
		}
		else
		{
			wait(&pid);
			execve(program, argv, env);
		}
	}
	else
	{
		arguments = get_user_input(program);

		execute(arguments, env);
	}

	return (0);
}
