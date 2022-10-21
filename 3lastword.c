
// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>
void	last_word(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
		i++;
	i -= 1;
	while(str[i] == '\t' || str[i] == 32)
		i--;
	while (i > 0)
	{	if(str[i] == 32 && str[i] == '\t')
			break;
		i--;
	}
	i++;
	while (str[i] != '\0' && str[i] != 32 && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
}
