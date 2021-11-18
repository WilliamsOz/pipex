/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/18 16:38:49 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipe_failed(t_data *data)
{
	ft_putstr("Pipe opening has failed\n");
	free_all_data(data, 0);
	exit (EXIT_FAILURE);
}

void	pipex(t_data *data)
{
	int		pipe_ret;
	int		pipe_fd[2];
	pid_t	son_pid;
	int		status;

	pipe_ret = pipe(pipe_fd);
	if (pipe_ret == -1)
		pipe_failed(data);
	son_pid = fork();
	if (son_pid == 0)
	{
		close(pipe_fd[1]); //ecriture
		
		close(pipe_fd[0]);
	}
	else
	{
		close(pipe_fd[0]);
		
	}
	waitpid(son_pid, &status, 0);
}

// file1 cmd1 cmd2 ... cmdn file2

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	data = NULL;
	data = check_all_errors(av, env, data);
	pipex(data);
	free_all_data(data, 0);
	return (0);
}
