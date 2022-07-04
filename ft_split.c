/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:08:47 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/28 13:09:20 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countwords(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*putword(char *s1, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		s1[j] = s[i - word_len];
		j++;
		word_len--;
	}
	s1[j] = '\0';
	return (s1);
}

static char	**split(char const *s, char c, char **s1, int nbwords)
{
	int		i;
	int		word_len;
	int		numword;

	i = 0;
	word_len = 0;
	numword = 0;
	while (numword < nbwords)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s1[numword] = malloc((word_len + 1));
		if (!s1)
			return (0);
		putword(s1[numword], s, i, word_len);
		word_len = 0;
		numword++;
	}
	s1[numword] = 0;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	int		nbwords;

	if (!s)
		return (NULL);
	nbwords = countwords(s, c);
	s1 = malloc(sizeof(char *) * (nbwords + 1));
	if (!s1)
		return (NULL);
	split(s, c, s1, nbwords);
	return (s1);
}
