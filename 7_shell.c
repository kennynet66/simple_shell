#include "kensa.h"
/**
* _strcmp - two strings check
* @elem1: first element
* @elem2: second element
* Return: true/false
*/
int _strcmp(char *elem1, char *elem2)
{
while (*elem1 && *elem2)
{
if (*elem1 != *elem2)
{
return (*elem1 - *elem2);
}
elem1++;
elem2++;
}
return (0);
}
/**
* _strcpy - function to duplicate two strings
* @location: pointer
* @path: ponter
* Return: @location
*/
char *_strcpy(char *location, char *path)
{
char *c = location;
while (*path != '\0')
{
*location = *path;
location++;
path++;
}
*location = '\0';
return (c);
}
/**
* _split - split string
* @str: string
* @sep: separator
* Return: divided path
*/
char **_split(char *str, char *sep)
{
char *label, **split_str;
int num = 0;
label = strtok(str, sep);
split_str = (char **)_calloc(100, sizeof(char *));
if (!split_str)
{
free(split_str);
return (NULL);
}
while (label)
{
split_str[num] = label;
label = strtok(NULL, sep);
num++;
}
return (split_str);
}
/**
* _strncat - function that concatenates two strings
* @location: string lctn
* @path: string source
* Return: 0
*/
char *_strncat(char *location, char *path)
{
int trev, val;
for (trev = 0; location[trev] != '\0'; trev += 1)
{}
for (val = 0; path[val] != '\0'; val += 1)
{
location[trev] = path[val];
trev++;
}
location[trev] = '\0';
return (location);
}
/**
* _strnlen - size of string
* @str: string
* Return: true/false
*
*/
int _strnlen(char *str)
{
int numb = 0;
while (str[numb] != '\0')
numb++;
return (numb);
}
