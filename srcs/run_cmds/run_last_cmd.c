/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:34:19 by user42            #+#    #+#             */
/*   Updated: 2021/11/24 13:34:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	last_cmd(t_data *data, t_lk_data *tmp, int count)
{
	data->child_pid = fork();
	if (data->child_pid < 0)
		fork_failed(data);
	if (data->child_pid == 0)
	{
		close(data->pipe_fd[count - 1][1]);
		dup2(data->pipe_fd[count - 1][0], STDIN_FILENO);
		close(data->pipe_fd[count - 1][0]);
		dup2(data->output_file, STDOUT_FILENO);
		close(data->output_file);
		execve(tmp->path_cmd, tmp->cmd, data->env);
		execve_failed(data);
	}
	else
	{
		close(data->output_file);
		close(data->pipe_fd[count -1][0]);
	}
	wait(&data->status);
}
