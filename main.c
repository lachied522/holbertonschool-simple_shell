#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[1]);
	//if (execve(argv[0], argv, NULL) == -1)
	//{
	//	perror("Error:");
	//}
	return (0);
}
