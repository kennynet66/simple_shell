#ifndef KENSA_H
#define KENSA_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


extern char **environ;
int _strncmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src);
char *search_path(char *command);
/* extern char **environ; */
struct Point
{
int x;
int y;
};
char **_split(char *str, char *sep);
char *_strncat(char *dest, char *src);
int _strnlen(char *s);
struct Person
{
char name[50];
int citNo;
float salary;
} person1;
char *_getenviron(char *env_var);
void *_callocs(unsigned int nmemb, unsigned int size);
void _environ(void);
int exect(char **args);
struct shell_file
{
int id;
char buff[50];
int ppid;
};

int empty_lin(char *buff);

#endif
