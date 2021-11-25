/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mid_cmds_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:00 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 17:29:06 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static void	mid_cmd(t_data *data, t_lk_data *tmp, int count)
{
	data->child_pid = fork();
	if (data->child_pid < 0)
		fork_failed(data);
	if (data->child_pid == 0)
	{
		close(data->output_file);
		dup2(data->pipe_fd[count - 1][0], STDIN_FILENO);
		close(data->pipe_fd[count - 1][0]);
		dup2(data->pipe_fd[count][1], STDOUT_FILENO);
		close(data->pipe_fd[count][1]);
		if (tmp->unknow_cmd == 0)
			execve(tmp->path_cmd, tmp->cmd, data->env);
		execve_failed(data);
	}
	else
	{
		close(data->pipe_fd[count - 1][0]);
		close(data->pipe_fd[count][1]);
	}
}

t_lk_data	*treat_mid_cmds(t_data *data, t_lk_data *tmp, int *ptr_count)
{
	while (data->cmd[(*ptr_count) + 1] != NULL)
	{
		mid_cmd(data, tmp, *ptr_count);
		*ptr_count += 1;
		tmp = tmp->next;
	}
	return (tmp);
}
