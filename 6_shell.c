#include "kensa.h"
/**
* search_path - show file src
* @elem: element
* Return: cmd src
*/
char *search_path(char *elem)
{
char *src = _getenviron("PATH"), *src_dup;
char **src_div;
char *src_add = NULL;
int i = 0, src_size = 0;
struct stat info;
if (stat(elem, &info) == 0)
{
return (elem);
}
src_dup = malloc(_strnlen(src) + 1);
src_dup = _strncpy(src_dup, src);
src_div = _split(src_dup, ":");
while (src_div[i])
{
src_size = _strnlen(src_div[i]);
if (src_div[i][src_size - 1] != '/')
{
src_add = _strncat(src_div[i], "/");
}
src_add = _strncat(src_div[i], elem);
if (stat(src_add, &info) == 0)
break;
i++;
}
free(src_dup);
if (!src_div[i])
{
free(src_div);
return (NULL);
}
free(src_div);
return (src_add);
}
