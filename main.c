#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main -
 * Return: Always 0.
 */
int main(int argc, char *argv[], char **env)
{
	char *program = argv[0];
	char **arguments;
	pid_t pid;

	if (isatty(0) == 1)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
		//	free(arguments);
		//	exit(98);
		}
		else if (pid == 0)
		{
			printf("%s: ", program);
			arguments = get_user_input(program);

			if (execve(arguments[0], arguments, env) == -1)
				perror("Error");
				//exit(98);
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

		if (execve(arguments[0], arguments, env) == -1)
			perror("Error");
	}

	return (0);
}
