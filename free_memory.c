#include "main.h"

void free_memory(char **memory)
{
	int i = 0;

	if (memory !=  NULL)
	{
		for (i = 0; memory[i] != NULL; i++)
			free(memory[i]);
		free(memory);
	}
}
