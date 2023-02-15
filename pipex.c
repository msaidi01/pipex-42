/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:25:21 by msaidi            #+#    #+#             */
/*   Updated: 2023/02/05 08:25:21 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1(int *fd, char **av, char **envp)
{
	char	**cmd;
	char	*path;
	char	**to_exec;
	char	*final_path;
	int		input;

	cmd = ft_split(av[2], ' ');
	if (cmd == NULL)
	{
		write(2, "command empty \n", 16);
		exit(1);
	}
	path = find_path(envp);
	to_exec = ft_split(path, ':');
	free(path);
	path = NULL;
	final_path = test_path(to_exec, cmd[0]);
	if (!final_path)
		exit(1);
	input = open(av[1], O_RDONLY);
	if_error(input);
	dup2(input, 0);
	close (input);
	dup2(fd[1], 1);
	close(fd[0]);
	execve(final_path, cmd, envp);
}

void	cmd2(int *fd, char **av, char **envp)
{
	char	**cmd2;
	char	*path;
	char	**to_exec;
	char	*final_path;
	int		output;

	cmd2 = ft_split(av[3], ' ');
	if (cmd2 == NULL)
	{
		write(2, "command empty\n", 15);
		exit(1);
	}
	path = find_path(envp);
	to_exec = ft_split(path, ':');
	final_path = test_path(to_exec, cmd2[0]);
	if (!final_path)
		exit(1);
	output = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if_error(output);
	dup2(output, 1);
	close (output);
	dup2(fd[0], 0);
	close(fd[1]);
	execve(final_path, cmd2, envp);
}

// void ft_leaks()
// {
// 	system("leaks pipex");
// }
int	main(int ac, char *av[], char *envp[])
{
	int		fd[2];
	int		pipechk;
	pid_t	pid[2];


	if (ac != 5)
	{
		write(2, "invalid number of args\n", 24);
		exit(1);
	}
	pipechk = pipe(fd);
	if_error(pipechk);
	pid[0] = fork();
	if_error(pid[0]);
	if (!pid[0])
		cmd1(fd, av, envp);
	pid[1] = fork();
	if_error(pid[1]);
	if (!pid[1])
		cmd2(fd, av, envp);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
