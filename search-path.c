#include "main.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

char *search_dir(char *filename, char *dir)
{
	DIR *d;
	struct dirent *entry;
	char *path;

	path = malloc(1000);

	d = opendir(dir);
	if (d)
	{
		while ((entry = readdir(d)) != NULL)
		{
			if (strcmp(entry->d_name, filename) == 0)
			{
				path = strcat(dir, "/");
				path = strcat(path, s);
				closedir(d);
				return (path);
			}
		}
		closedir(d);
	}

	free(path);

	return (NULL);
}

/**
 * search_path - search for a file inside PATH
 * @filename:
 * @env:
 * Return: path to file
 */
char *search_path(char *filename, char **env)
{
	char *path;
	char *path_var;
	char *dir;
	int i;

	path = NULL;
	path_var = NULL;
	i = 0;

	while (env[i] != NULL)
	{
		if (strcmp(env[i], "PATH=", 5) == 0)
		{
			/* this skips the "PATH=" prefix */
			path_var = env[i] + 5;
			break;
		}
		i++;
	}

	if (path_var)
	{
		dir = strtok(path_var, ":");
		while (dir != NULL)
		{
			path = search_dir(filename, dir);
			if (path)
				return (path);
			dir = strtok(NULL, ":");
		}
	}

	return (NULL);
}
