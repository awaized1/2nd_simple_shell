#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 * @env: An array of strings containing the environment variables.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	prompt(av, env);

	return (0);
}
