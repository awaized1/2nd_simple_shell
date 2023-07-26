#include "main.h"
#include <sys/wait.h>

/**
 * _strcspn - Calculates the index of the first occurrence of the character @c
 *            in the string @str.
 * @str: The string to be searched.
 * @c: The character to be found.
 *
 * Return: The index position of @c in @str, or the total number of characters
 *         in @str if @c is not found.
 */

size_t _strcspn(const char *str, char c)
{
	size_t i = 0;

	for (; str[i]; i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (i);
}

/**
 * prompt - Executes a command entered in the terminal.
 *
 * @av: An array of strings representing the argument vector.
 * @env: An array of strings representing the environment vector.
 */

void prompt(char **av, char **env)
{
	pid_t child_pid;
	ssize_t num_char;
	size_t n = 0;
	int status;
	char *string = NULL, *argv[] = {NULL, NULL};

	while (1)
	{
		/* when the input is expected from a user in (interactive mode) */
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1) /*It handles the EOF condition */
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		/* It removes newline character */
		string[_strcspn(string, '\n')] = 0;

		argv[0] = string;

		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
	exit(EXIT_SUCCESS);
}
