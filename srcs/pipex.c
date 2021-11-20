/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/20 13:48:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	destroy_data(t_data *data)
{
	ft_putstr("Pipe opening has failed\n");
	// free_lk()
	free_all_data(data, 0);
	exit (EXIT_FAILURE);
}

void	pipex(t_data *data)
{
	// pipe_fd[0] == lecture && pipe_fd[1] == ecriture
	data->pipe_ret = pipe(data->pipe_fd);
	if (data->pipe_ret == -1)
		destroy_data(data);
	data->child_pid = fork();
	if (data->child_pid == 0)
	{
		close(data->pipe_fd[0]);
		close(data->fd_file[1]);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
		dup2(data->fd_file[0], STDIN_FILENO);
		execve(data->lk_data->path_cmd, data->lk_data->cmd, data->env);
		PRINT("execve_failed\n");
	}
	else
	{
		close(data->fd_file[0]);
		close(data->pipe_fd[1]);
	}
	wait(&data->status);
	char buff[32];
	write(1, buff, read(data->pipe_fd[0], buff, 32));
}

// file1 cmd1 cmd2 ... cmdn file2

int	main(int ac, char **av, char **env) //proteger les mallocs de la lk
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	data = NULL;
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	data->env = env;
	pipex(data);
	free_all_data(data, 0);
	return (0);
}
