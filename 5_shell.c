#include "kensa.h"
/**
* _callocs - allocate function
* @argc: argument
* @len: length
* Return: zero
*/
void *_callocs(unsigned int argc, unsigned int len)
{
unsigned int loc = 0;
char *show = NULL;
if (argc == 0 || len == 0)
return (NULL);
show = malloc(argc * len);
if (show == NULL)
return (NULL);
for (; loc < (argc * len); loc++)
{
show[loc] = 0;
}
return (show);
}
