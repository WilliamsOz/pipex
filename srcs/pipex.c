/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/23 15:16:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// pipe_fd[0] == lecture && pipe_fd[1] == ecriture
	// data->pipe_ret = pipe(data->pipe_fd);
	// if (data->pipe_ret == -1)
	// 	pipe_opening_has_failed(data);
	// data->child_pid = fork();
	// if (data->child_pid == 0)
	// {
	// 	close(data->pipe_fd[0]);
	// 	close(data->output_file);
	// 	dup2(data->pipe_fd[1], STDOUT_FILENO);
	// 	dup2(data->input_file, STDIN_FILENO);
	// 	execve(data->lk_data->path_cmd, data->lk_data->cmd, data->env);
	// 	PRINT("execve_failed\n");
	// }
	// else
	// {
	// 	close(data->input_file);
	// 	close(data->pipe_fd[1]);
	// }
	// wait(&data->status);
	// char buff[32];
	// write(1, buff, read(data->pipe_fd[0], buff, 32));
	// close(data->output_file);
	// close(data->pipe_fd[0]);

void	first_cmd_child_close(t_data *data, int count)
{
	close(data->output_file);
	close(data->pipe_fd[0][0]);
	count++;
	while (data->pipe_fd[count] != NULL)
	{
		close(data->pipe_fd[count][0]);
		close(data->pipe_fd[count][1]);
		count++;
	}
}

void	first_cmd(t_data *data, t_lk_data *tmp)
{
	data->child_pid = fork();
	if (data->child_pid < 0)
		fork_failed(data);
	if (data->child_pid == 0)
	{
		first_cmd_child_close(data, 1);
		dup2(data->pipe_fd[0][1], STDOUT_FILENO);
		close(data->pipe_fd[0][1]);
		execve(tmp->path_cmd, tmp->cmd, data->env);
		execve_failed(data);
	}
	else
		close(data->output_file);
	wait(&data->status);
}

void	last_cmd(t_data *data, t_lk_data *tmp, int count)
{
	data->child_pid = fork();
	if (data->child_pid < 0)
		fork_failed(data);
	if (data->child_pid == 0)
	{
		close(data->pipe_fd[count - 1][1]);
		dup2(data->pipe_fd[count - 1][0], STDIN_FILENO);
		dup2(data->output_file, STDOUT_FILENO);
		close(data->output_file);
		close(data->pipe_fd[count - 1][0]);
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

void	pipex(t_data *data, int count)
{
	t_lk_data	*tmp;

	tmp = data->lk_data;
	first_cmd(data, tmp);
	count++;
	tmp = tmp->next;
	// while (data->cmd[count + 1] != NULL)
	// {
	// 	// mid_cmd(data);
	// 	count++;
	// 	tmp = tmp->next;
	// }
	last_cmd(data, tmp, count);
	// wait(&data->status);
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
