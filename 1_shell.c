#include "kensa.h"

/**
 * empty_lin - emptiness
 * @stats: line
 * Return: tr/fl
 */

int empty_lin(char *stats)
{
	int loop;

	for (loop = 0; stats[loop] != '\0'; loop++)
	{
		if (stats[loop] != ' ')
			return (0);
	}
	return (1);
}

