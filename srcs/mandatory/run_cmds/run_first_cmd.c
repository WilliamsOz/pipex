/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:33:52 by user42            #+#    #+#             */
/*   Updated: 2021/11/25 02:04:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static void	here_doc(t_data *data)
{
	if (data->is_there_here_doc == 1)
	{
		dup2(data->here_doc_pipe[1], STDIN_FILENO);
		close(data->here_doc_pipe[1]);
	}
	else
	{
		dup2(data->input_file, STDIN_FILENO);
		close(data->input_file);
	}
}

void	first_cmd(t_data *data, t_lk_data *tmp)
{
	data->child_pid = fork();
	if (data->child_pid < 0)
		fork_failed(data);
	if (data->child_pid == 0)
	{
		close(data->pipe_fd[0][0]);
		close(data->output_file);
		here_doc(data);
		dup2(data->pipe_fd[0][1], STDOUT_FILENO);
		close(data->pipe_fd[0][1]);
		execve(tmp->path_cmd, tmp->cmd, data->env);
		execve_failed(data);
	}
	else
	{
		close(data->input_file);
		close(data->pipe_fd[0][1]);
	}
	wait(&data->status);
}
