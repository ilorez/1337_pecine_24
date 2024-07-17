/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:01:40 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/17 09:37:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_is_sep(char c, char *seps)
{
	int	i;

	i = 0;
	while (seps[i])
		if (seps[i++] == c)
			return (1);
	return (0);
}

int	ft_c_ws(char *str, char *seps)
{
	int	i;
	int	w;

	w = 0;
	i = 0;	
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], seps))
			i++;
		if (str[i])
			w++;
		while (str[i]  && !ft_is_sep(str[i], seps))
			i++;
	}	
	return (w);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	char	*word;
	char	*start;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (ft_c_ws(str, charset) + 1));
	while (*str)
	{
		while (*str != '\0' && ft_is_sep(*str, charset))
			str++;
		if (*str)
		{
			start = str;
			while (*str != '\0' && !ft_is_sep(*str, charset))
				str++;
			word = (char *)malloc(sizeof(char) * (str - start + 1));
			strings[i++] = word;
			while (start != str)
				*word++ = *start++;
			*word = '\0';
		}
	}
	strings[i] = 0;
	return (strings);
}

/*int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	strs = ft_split(argv[argc * 0 + 1], argv[2]);
	i = 0;
	while (strs[i])
	{
		printf("string %d: [%s]\n", i, strs[i]);
		i++;
	}
	return (0);
}*/
