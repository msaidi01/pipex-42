/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:51:16 by msaidi            #+#    #+#             */
/*   Updated: 2023/02/14 11:19:12 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *path, char *command)
{
	char	*tmp;
	char	*final;

	tmp = ft_strjoin(path, "/");
	final = ft_strjoin(tmp, command);
	free(tmp);
	return (final);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ps1[i] == ps2[i] && ps1[i] && ps2[i] && i < n - 1)
		i++;
	return (ps1[i] - ps2[i]);
}

char	*test_path(char	**to_test, char *path)
{
	char	*final_path;
	int		i;

	i = 0;

	if(!path || path == '\0')
	{
		write(2, "command error\n", 15);
		exit(1);
	}
	if (!access(path, F_OK | X_OK))
		return (path);
	if (!ft_strncmp(path, "./", 2))
		return (path);
	while (to_test[i])
	{
		final_path = join_path(to_test[i], path);
		if (!access(final_path, F_OK | X_OK))
			return (final_path);
		free(final_path);
		i++;
	}
	final_path = NULL;
	perror("command not found");
	return (NULL);
}

char	*find_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_strdup(&envp[i][5]);
			break ;
		}
		i++;
	}
	if (!path)
	{
		perror("cmd1 path");
		exit(0);
	}
	return (path);
}
