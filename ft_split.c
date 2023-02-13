/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:25:02 by msaidi            #+#    #+#             */
/*   Updated: 2023/02/13 14:42:12 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	**makestrs(char const *s, char c)
{
	int		word;
	char	**strs;

	word = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		while (*s != c && *s != '\0')
			s++;
		word++;
	}
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (!strs)
		return (NULL);
	strs[word] = NULL;
	return (strs);
}

static char	**free_all(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
	strs = NULL;
	return (strs);
}

static int	lenstr(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	char	**fillstrs(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	strs = makestrs(s, c);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		strs[j] = (char *)malloc(sizeof(char) * (lenstr(s + i, c) + 1));
		if (!strs[j])
			return (free_all(strs, j));
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || s[0] == '\0')
		return (NULL);
	strs = fillstrs(s, c);
	if (!strs)
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			strs[j][k++] = s[i++];
		strs[j++][k] = '\0';
	}
	return (strs);
}
