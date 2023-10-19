#include "kensa.h"
/**
* search_path - show file source
* @elem: element
* Return: cmd source
*/
char *search_path(char *elem)
{
char *source = _getenviron("PATH"), *source_dup;
char **source_div;
char *source_add = NULL;
int i = 0, source_size = 0;
struct stat info;
if (stat(elem, &info) == 0)
{
return (elem);
}
source_dup = malloc(_strnlen(source) + 1);
source_dup = _strncpy(source_dup, source);
source_div = _split(source_dup, ":");
while (source_div[i])
{
source_size = _strnlen(source_div[i]);
if (source_div[i][source_size - 1] != '/')
{
source_add = _strncat(source_div[i], "/");
}
source_add = _strncat(source_div[i], elem);
if (stat(source_add, &info) == 0)
break;
i++;
}
free(source_dup);
if (!source_div[i])
{
free(source_div);
return (NULL);
}
free(source_div);
return (source_add);
}
