#include "main.h"

/**
 * main - Entry point of the program that executes a command.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the argument vector.
 * @env: An array of strings representing the environment vector.
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);

	return (0);
}
