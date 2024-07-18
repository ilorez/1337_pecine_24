#include <stdio.h>

// Function prototype
void	ft_foreach(int *tab, int length, void(*f)(int));

// Example callback function
void	print_number(int n)
{
	printf("%d\n", n);
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	int length = 5;

	ft_foreach(tab, length, print_number);

	return 0;
}
