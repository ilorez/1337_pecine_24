//#include <stdio.h>
int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(int ac, char **av)
{
	printf("the result is : %d\n", ft_strcmp(av[ac * 0 +  1], av[2]));
}*/
