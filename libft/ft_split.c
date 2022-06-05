/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:44:13 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:14:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c, int *i)
{
	int	count;

	count = 0;
	if (s[0] != '\0')
	{
		while (s[*i])
		{
			if (s[*i - 1] != c && s[*i] == c)
				count++;
			*i += 1;
		}
		if (s[*i - 1] != c && s[*i] == '\0')
			count++;
		*i = 0;
	}
	return (count);
}

static int	get_word_size(char const *s, char c, int *i)
{
	int	size_word;

	size_word = 0;
	while (s[*i] == c && s[*i])
		*i += 1;
	while (s[*i] != c && s[*i] != '\0')
	{
		size_word++;
		*i += 1;
	}
	*i += 1;
	return (size_word);
}

static void	get_word(char const *s, char c, int *i, char *word)
{
	int	j;

	j = 0;
	while (s[*i] == c && s[*i])
		*i += 1;
	while (s[*i] != c && s[*i] != '\0')
	{
		word[j] = s[*i];
		*i += 1;
		j++;
	}
	word[j] = '\0';
	*i += 1;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;
	int		j;
	int		k;

	i = 1;
	words = count_words(s, c, &i);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (s[0] == '\0')
		array[0] = NULL;
	j = -1;
	k = 0;
	while (++j < words)
	{
		array[j] = malloc((get_word_size(s, c, &i) + 1) * sizeof(char));
		if (array[j] == NULL)
			return (NULL);
		get_word(s, c, &k, array[j]);
	}
	array[j] = NULL;
	return (array);
}
