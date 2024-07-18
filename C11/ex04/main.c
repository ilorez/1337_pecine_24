#include <stdio.h>

// Function prototype
int	ft_is_sort(int *tab, int length, int(*f)(int, int));

// Example comparison function
int	compare(int a, int b)
{
	return (a - b);
}

int main()
{
	int sorted_tab[] = {1, 2, 3, 4, 5};
	int unsorted_tab[] = {5, 3, 1, 4, 2};
	int length = 5;

	if (ft_is_sort(sorted_tab, length, compare))
		printf("The sorted_tab is sorted.\n");
	else
		printf("The sorted_tab is not sorted.\n");

	if (ft_is_sort(unsorted_tab, length, compare))
		printf("The unsorted_tab is sorted.\n");
	else
		printf("The unsorted_tab is not sorted.\n");

	return 0;
}
