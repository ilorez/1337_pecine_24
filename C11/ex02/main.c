#include <stdio.h>

// Function prototype
int	ft_any(char **tab, int(*f)(char*));

// Example callback function
int	contains_a(char *str)
{
	while (*str)
	{
		if (*str == 'a' || *str == 'A')
			return (1);
		str++;
	}
	return (0);
}

int main()
{
	char *tab[] = {"hello", "world", "ilorez", "toto", "nooo", NULL};

	if (ft_any(tab, contains_a))
		printf("At least one string contains the letter 'a'\n");
	else
		printf("No string contains the letter 'a'\n");

	return 0;
}

