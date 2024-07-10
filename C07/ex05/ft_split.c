/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:01:40 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/10 17:01:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *seps)
{
	int	i;

	while(seps[i])
		if (seps[i++] == c)
			return (0);
	return (1);
}

int	ft_count_words(char *str,char seps)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i]))
			if (i > 0 && !ft_is_sep(str[i - 1])
					w++;
		i++;
	}
	return (w);
}

char	**ft_split(char	*str, char *charset)
{
	char	**strings;
	char	*start;
	int	i;
	char	*word;
		
	strings = malloc(sizeof(char) * (ft_count_worlds(str, charset)));
	i = 0;
	start = str;
	while (*str)
	{
		if (*(str+1) && str == start && ft_is_sep(*str, charset))
			start++;
		if (str != start && ft_is_sep(*str, charset))				
		{
			//if (!ft_is_sep(*(str-1), charset))
			//{
				word = malloc(str - start + 1);
				strings[i] = word; 
				while (start != str)
					(*word)++ = (*start)++; // go from start of word to the position we are in now that count as a word
				*word = 0; // null terminate the word
				i++; // go to next word
			start++;
		}
		str++; // go next letter
	}
	
}
