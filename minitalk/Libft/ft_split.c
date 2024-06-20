/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:21:23 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/02 13:11:41 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c);
static int	ft_free(char **str);
static void	fill_word(char *dest, const char *src, char c);
static int	split_word(char **split, const char *str, char c);

char	**ft_split(const char *str, char c)
{
	char	**words;
	int		count;

	count = count_words(str, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	words[count] = 0;
	if (split_word(words, str, c) == -1)
		return (NULL);
	return (words);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0')
			&& !(str[i] == c || str [i] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static void	fill_word(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (!(src[i] == c || src [i] == '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	split_word(char **split, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == c || str[i + j] == '\0'))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (ft_free(split));
			fill_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

static int	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (-1);
}
