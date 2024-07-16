/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:01:40 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/16 12:06:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	ft_just_again(char **start, char **str, char **word)
{
	while (*start != *str)
		*(*word)++ = *(*start)++;
	(**word) = 0;
	(*start)++;
}

int	ft_make_it_possible(char *str, int *w, char **strings, char *charset)
{
	if (!(*str))
	{
		strings[0] = 0;
		return (0);
	}
	*w = (ft_count_words(str, charset));
	strings = malloc(sizeof(char *) * ((*w) + 1));
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
	if (!ft_make_it_possible(str, &w, strings, charset))
		return (strings);
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
			ft_just_again(&start, &str, &word);
		}
		str++;
	}
	strings[i] = 0;
	return (strings);
}

// Test function
int test_ft_split(char *str, char *charset, char **expected)
{
    char **result = ft_split(str, charset);
    int i = 0;

    // Check the result against the expected values
    while (result[i] && expected[i])
    {
        if (strcmp(result[i], expected[i]) != 0)
        {
            printf("Expected '%s' but got '%s'\n", expected[i], result[i]);
            return 0; // Return error
        }
        i++;
    }

    // Check if both result and expected end at the same time
    if (result[i] != 0 || expected[i] != 0)
    {
        printf("Mismatch in array length\n");
        return 0; // Return error
    }

    // Free allocated memory
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return 1; // Return success
}

int main()
{
    int result = 1;

    // Test cases
    char *expected1[] = {" hello", "world", "this", "is", "a", "test ", 0};
    result &= test_ft_split(" hello,world,this,is,a,test ", ",", expected1);

    char *expected2[] = {"one", "two", "three", "four", 0};
    result &= test_ft_split("one;two;three;four", ";", expected2);

    char *expected3[] = {"abc", "def", "ghi", "jkl", 0};
    result &= test_ft_split("abc:def:ghi:jkl", ":", expected3);

    char *expected4[] = {"split", "this", "string", "with", "pipes", 0};
    result &= test_ft_split("split|this|string|with|pipes", "|", expected4);

    char *expected5[] = {"space", "separated", "string", 0};
    result &= test_ft_split(" space separated string ", " ", expected5);

    char *expected6[] = {"nospacesorseparators", 0};
    result &= test_ft_split("nospacesorseparators", ",", expected6);

    char *expected7[] = {"double", "commas", 0};
    result &= test_ft_split("double,,commas", ",", expected7);

    char *expected8[] = {0};
    result &= test_ft_split("", ",", expected8);

    char *expected9[] = {0};
    result &= test_ft_split(",,,,", ",", expected9);

    char *expected10[] = {0};
    result &= test_ft_split("    ", " ", expected10);

    char *expected11[] = {"one", "two", "three", "four", 0};
    result &= test_ft_split("one,two;three:four", ",;:", expected11);

    char *expected12[] = {"abc", "123", 0};
    result &= test_ft_split("abcXYZ123", "XYZ", expected12);

    char *expected13[] = {"hello", "world", "this", "is", "test", 0};
    result &= test_ft_split("hello@world#this$is!test", "@#$!", expected13);

    char *expected14[] = {"héllo", "你好", "привет", "こんにちは", 0};
    result &= test_ft_split("héllo,你好,привет,こんにちは", ",", expected14);

    char *expected15[] = {"start", "word", 0};
    result &= test_ft_split(",start,word", ",", expected15);

    char *expected16[] = {"end", "word", 0};
    result &= test_ft_split("end,word,", ",", expected16);

    char *expected17[] = {"a", "b", "c", 0};
    result &= test_ft_split("a,,b,,,c", ",", expected17);

    char *expected18[] = {0};
    result &= test_ft_split(",,,,", ",", expected18);

    char *expected19[] = {"word1", "word2", "word3", "word4", 0};
    result &= test_ft_split("word1 word2\tword3\nword4", " \t\n", expected19);

    char *expected20[] = {"verylongstringwithnoseparatorsatall", 0};
    result &= test_ft_split("verylongstringwithnoseparatorsatall", ",", expected20);

    char *expected21[] = {"word1", "word2", 0};
    result &= test_ft_split("word1\\,word2", "\\,", expected21);

    char *expected22[] = {"teststring", 0};
    result &= test_ft_split("teststring", "", expected22);

    char *expected23[] = {0};
    result &= test_ft_split("abcdef", "abcdef", expected23);

    // Print result
    if (result)
    {
        printf("no errors\n");
    }
    else
    {
        printf("error\n");
    }

    return 0;
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
