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
 * main - accepts commands
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

		if (input[0] == '\0')
		{
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			if (execlp(input, input, (char *)NULL) == -1) {
				fprintf(stderr, "Command not found: %s\n", input);
				exit(EXIT_FAILURE);
			}
		} else
		{
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
				fprintf(stderr, "Error: The command did not exit successfully.\n");
			}
		}
	}

	return (0);
}
