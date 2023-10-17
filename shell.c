#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
/**
 * display_prompt - display prompt
 * Return: void
 */

void display_prompt(void)
{
	printf("#cisfun$ ");
}
/**
 * main - accept commands
 * Return: void
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	pid_t pid;

	while (1)
	{
		display_prompt();

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			execlp(input, input, (char *)NULL);

			fprintf(stderr, "Command not found: %s\n", input);
			exit(EXIT_FAILURE);
		} else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}

	return (0);
}