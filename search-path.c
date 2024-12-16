#include "main.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>

char *search_dir(char *s, char *dir)
{
	DIR *d;
	struct dirent *entry;
	char *path;

	d = opendir(dir);
	if (d)
	{
		while ((entry = readdir(d)) != NULL)
		{
			if (strcmp(entry->d_name, s) == 0)
			{
				printf("Found it!");
				path = strcat(dir, "/");
				path = strcat(path, s);
				closedir(d);
				return (path);
			}
		}
		closedir(d);
	}

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
	char **ptr = env;
	char *key;
	char *value;
	char *dir;

	printf("We are looking for %s\n", filename);

	while (*ptr != NULL)
	{
		key = strtok(*ptr, "=");
		
		if (strcmp(key, "PATH") == 0)
		{
			value = strtok(NULL, "=");

			dir = strtok(value, ":");

			while (dir != NULL)
			{
				dir = strtok(NULL, ":");
				path = search_dir(filename, dir);
				printf("%s", path);
			}

			break;
		}
		ptr++;
	}

	return (path);
}
