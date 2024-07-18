#include <stdio.h>
#include <stdlib.h>

// Function prototype
int	*ft_map(int *tab, int length, int(*f)(int));

// Example mapping function
int	square(int n)
{
	return (n * n);
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	int length = 5;
	int *mapped_tab;
	int i;

	mapped_tab = ft_map(tab, length, square);
	if (!mapped_tab)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	for (i = 0; i < length; i++)
	{
		printf("%d\n", mapped_tab[i]);
	}

	free(mapped_tab);
	return 0;
}
