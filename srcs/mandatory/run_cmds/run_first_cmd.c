/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:33:52 by user42            #+#    #+#             */
/*   Updated: 2021/11/26 11:44:16 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static void	link_here_doc(t_data *data)
{
	data->input_file = open("1", O_RDONLY);
	if (data->is_there_here_doc == 1)
		dup2(data->here_doc_pipe[0], STDIN_FILENO);
	else
		dup2(data->input_file, STDIN_FILENO);
}

void	first_cmd(t_data *data, t_lk_data *tmp)
{
	data->child_pid = fork();
	if (data->child_pid < 0)
		fork_failed(data);
	if (data->child_pid == 0)
	{
		link_here_doc(data);
		close(data->pipe_fd[0][0]);
		if (data->is_there_here_doc == 0)
			close(data->input_file);
		dup2(data->pipe_fd[0][1], STDOUT_FILENO);
		close(data->pipe_fd[0][1]);
		if (tmp->unknow_cmd == 0 &&
			data->is_there_here_doc == 0 && data->input_file != -1)
			execve(tmp->path_cmd, tmp->cmd, data->env);
		execve_failed(data);
	}
	else
	{
		if (data->is_there_here_doc == 1)
			close(data->here_doc_pipe[0]);
		else if (data->input_file != -1)
			close(data->input_file);
		close(data->pipe_fd[0][1]);
	}
	wait(&data->status);
}
