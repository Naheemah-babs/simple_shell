#include "shell.h"
/**
 * _executable– returns true if shell is executable
 * @info: struct address
 *
 * Return: 1 if executable mode, 0 otherwise
 */

int _executable(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * seperator- if character is a seperator
 * @cter: the char to check
 * @seperates: the delimeter string
 * Return: 1 if true, 0 if false
 */
int seperator(char cter, char *seperates)
{
	while (*seperates)
		if (*seperates++ == cter)
			return (1);
	return (0);
}

/**
 * _alpha - checks for characters that aren’t delimiters
 * @cinput: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _alpha(int cinput)
{
	if ((cinput >= 'a' && cinput <= 'z') || (cinput >= 'A' && cinput <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _strcon - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _strcon(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
