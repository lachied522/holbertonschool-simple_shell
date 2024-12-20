#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

void execute(char **arguments, char **env);
char **get_user_input();
char *search_path(char *filename, char **env);
bool handle_whitespace(char *str);

#endif
