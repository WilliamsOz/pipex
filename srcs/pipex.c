/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/21 17:21:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_data *data)
{
	// pipe_fd[0] == lecture && pipe_fd[1] == ecriture
	data->pipe_ret = pipe(data->pipe_fd);
	if (data->pipe_ret == -1)
		pipe_opening_has_failed(data);
	data->child_pid = fork();
	if (data->child_pid == 0)
	{
		close(data->pipe_fd[0]);
		close(data->output_file);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
		dup2(data->input_file, STDIN_FILENO);
		execve(data->lk_data->path_cmd, data->lk_data->cmd, data->env);
		PRINT("execve_failed\n");
	}
	else
	{
		close(data->input_file);
		close(data->pipe_fd[1]);
	}
	wait(&data->status);
	char buff[32];
	write(1, buff, read(data->pipe_fd[0], buff, 32));
	close(data->output_file);
	close(data->pipe_fd[0]);
}

// file1 cmd1 cmd2 ... cmdn file2

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	data = NULL;
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	data->env = env;
	pipex(data);
	destroy_data(data);
	return (0);
}
