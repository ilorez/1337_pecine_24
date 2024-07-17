/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:01:40 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/16 18:25:53 by znajdaou         ###   ########.fr       */
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

int	ft_count_words(char *str, char *seps)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], seps))
			if (i > 0 && !ft_is_sep(str[i - 1], seps))
				w++;
		i++;
	}
	if (!ft_is_sep(str[i - 1], seps))
		w++;
	return (w);
}

void	ft_copy_word(char **start, char **str, char **word)
{
	while (*start != *str)
		*(*word)++ = *(*start)++;
	(**word) = '\0';
	(*start)++;
}

int	ft_make_it_possible(char *str, int *w, char **strings, char *charset)
{
	if (!(*str))
	{
		*w = 0;
		strings[0] = NULL;
		return (0);
	}
	(*w) = (ft_count_words(str, charset));
	strings = (char **)malloc(sizeof(char *) * ((*w) + 1));
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	char	*start;
	int		i;
	char	*word;
	int		w;

	strings = malloc(1);
	ft_make_it_possible(str, &w, strings, charset);
	i = 0;
	start = str;
	while (i < w)
	{
		if (str == start && ft_is_sep(*str, charset))
			start++;
		else if ((str != start && (ft_is_sep(*str, charset) || !(*str))))
		{
			word = (char *)malloc(sizeof(char) * (str - start + 1));
			strings[i++] = word;
			ft_copy_word(&start, &str, &word);
		}
		str++;
	}
	strings[i] = NULL;
	return (strings);
}

/*int    main(int argc, char **argv)
{
	char **strs;
	int    i;

	strs = ft_split(argv[argc*0 +1], argv[2]);
	i = 0;
	while (strs[i])
	{
		printf("string %d: [%s]\n",i ,strs[i]);
		i++;
	}
	return (0);
}*/
