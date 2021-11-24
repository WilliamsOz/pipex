/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 14:09:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	mid_cmd(t_data *data, t_lk_data *tmp, int count)
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
		execve(tmp->path_cmd, tmp->cmd, data->env);
	}
	else
	{
		close(data->pipe_fd[count - 1][0]);
		close(data->pipe_fd[count][1]);
	}
}

void	pipex(t_data *data, int count)
{
	t_lk_data	*tmp;

	tmp = data->lk_data;
	first_cmd(data, tmp);
	tmp = tmp->next;
	count++;
	while (data->cmd[count + 1] != NULL)
	{
		mid_cmd(data, tmp, count);
		count++;
		tmp = tmp->next;
	}
	last_cmd(data, tmp, count);
	close_pipex_fd();
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	data = NULL;
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	data->env = env;
	pipex(data, 0);
	destroy_data(data);
	return (0);
}
