/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:25:29 by msaidi            #+#    #+#             */
/*   Updated: 2023/02/05 08:25:29 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

char	*find_path(char **envp);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	if_error(int chk);
char	*ft_strjoin(char *s1, char *s2);
char	*join_path(char *path, char *command);
char	*test_path(char	**to_test, char *path);
void	cmd1(int *fd, char **av, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

#endif