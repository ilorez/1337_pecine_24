
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print_strs(char *strs[], int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		ft_putstr(strs[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_sort_strs(char *strs[], int len)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < len - 1)
	{
		j = 1;
		while (j < len - 1)
		{
			if (ft_strcmp(strs[j], strs[j + 1]) > 0)
			{
				temp = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(const int argc, char *argv[])
{
	if (argc > 1)
	{
		ft_sort_strs(argv, argc);
		ft_print_strs(argv, argc);
	}
	return (0);
}
