#include <stdio.h>

// Function prototype
int	ft_count_if(char **tab, int length, int(*f)(char*));

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
	char *tab[] = {"hello", "world", "foo", "me a", "me too a"};
	int length = 5;
	int count;

	count = ft_count_if(tab, length, contains_a);
	printf("Number of strings containing the letter 'a': %d\n", count);

	return 0;
}

