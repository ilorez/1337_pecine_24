#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int ac, char **av)
{
	char	*str;
	int	str_len;
	char	*result;
	char	*first_word_adr;
	int	i;
	int	is_w;

	i = 0;
	if (ac >= 2)
	{
		str = av[1];
		str_len = ft_strlen(str);
		result = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!result)
		{			
			write(1, "\n", 1);
			return (0);
		}
		// skip first spaces
		while (*str && ft_is_space(*str))
			str++;

		first_word_adr = str;	
		// skip word
		while (*str && !ft_is_space(*str))
			str++;
		// cpy word seprate with one space to result
		while(*str)
		{
			is_w = 0;
			while (*str && ft_is_space(*str))
				str++;
			if (*str)
				is_w = 1;
			while (*str && !ft_is_space(*str))
				result[i++] = *str++;
			if (is_w)
				result[i++] = ' ';
		}
		// put last word
		
		while (*first_word_adr && !ft_is_space(*first_word_adr))
			result[i++] = *first_word_adr++;

		result[i] = '\0';
		i = 0;
		while (result[i])
			write(1, &result[i++], 1);
		free(result);
	}
	write(1, "\n", 1);
	return (0);
}
