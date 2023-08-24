#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

/* string_funtions_1 */
int _putchar(char);
int _puts(char *);
char *_strcat(char *, char *);
char *_strncat(char *, char *, int);
int _strlen(char *);

/* string_funtions_2 */
int _strcmp(char *, char *);
char **splitstr(char *);
char *_strcpy(char *, char *);
char *_strdup(char *);
int _strncmp(char *, char *, int);

/* string_functions_3*/
char ***split_str_prime(char *);

/* executionners */
void exec_non_interactive(char **envp);
void executionner_prime(char **, char *, int);
void executionner(char *, int, char **, char **);
void exec1(char *, char **, char **);
void exec2(char *);
void exec3(char *, char **);
void exec4(char **, char **);
/* _realloc */
void *_realloc(void *, unsigned int, unsigned int);

/* path_handling_functions */
char *_getenv(char *, char **);
char *get_command(char *, char **);
void print_env(char **);
int change_dir(char **, char **);

/* checker */
int checker(char *, char **);

/* _strtok */
char *_strtok_r(char *, char *, char **);

/* _getline*/
ssize_t non_interactive_getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _getchar(void);

/* env */
int _setenv(char *, char *, bool);
int _unsetenv(char *);

/* is_cmd */
int is_command(char *cmd, char **envp);

/* the enviroment pointer*/
extern char **environ;
#endif
