#include "shell.h"

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**
 * _strlen - tring codeeturns the length of a string.
 * @s: point to characters string.
 *
 * Return: The len of the charstring.
 */

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _strcpy - Code will Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the dest of copied string leter
 * @src: Pointer to the source of the source string.
 *
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Code Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */

char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strncat - Code can Concantenates two strings where n number
 *            of bytes is copied from source.
 * @dest: Pointer to dest string.
 * @src: Pointer to src string.
 * @n: n bytes to copiesfrom src.
 *
 * Return: Pointer to dest string.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t b;

	for (b = 0; b < n && src[b] != '\0'; b++)
		dest[dest_len + b] = src[b];
	dest[dest_len + b] = '\0';

	return (dest);
}
