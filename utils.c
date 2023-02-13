/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:25:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/02/05 08:25:40 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dp;
	size_t	i;

	i = ft_strlen(s1);
	dp = (char *)malloc (sizeof(char) * (i + 1));
	if (!dp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dp[i] = s1[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}

void	if_error(int chk)
{
	if (chk < 0)
	{
		perror("Pipex");
		exit(0);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	char	*res;
	size_t	lenjoin;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lenjoin = ft_strlen(s1) + ft_strlen(s2);
	s = malloc (sizeof(char) * (lenjoin + 1));
	if (!s)
		return (NULL);
	res = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (res);
}
