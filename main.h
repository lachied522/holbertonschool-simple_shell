#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

#ifndef MAIN
#define MAIN

char **get_user_input();
char *search_path(char *filename, char **env);

#endif
