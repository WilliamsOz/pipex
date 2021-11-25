/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:21:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 07:36:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	free_data(t_data *data)
{
	free(data);
	data = NULL;
}

void	free_all_data(t_data *data, int count)
{
	while (data->splited_path[count] != NULL)
	{
		free(data->splited_path[count]);
		count++;
	}
	free(data->splited_path[count]);
	free(data->splited_path);
	free(data->cmd);
	free_data(data);
}

void	free_lk(t_data *data, int count)
{
	t_lk_data	*tmp;

	while (data->lk_data != NULL)
	{
		tmp = data->lk_data;
		data->lk_data = data->lk_data->next;
		while (tmp->cmd[count] != NULL)
		{
			free(tmp->cmd[count]);
			count++;
		}
		free(tmp->cmd[count]);
		free(tmp->cmd);
		free(tmp->path_cmd);
		free(tmp);
		count = 0;
	}
}

void	free_pipe(t_data *data, int count)
{
	while (data->pipe_fd[count] != NULL)
	{
		free(data->pipe_fd[count]);
		count++;
	}
	free(data->pipe_fd[count]);
	free(data->pipe_fd);
}

void	destroy_data(t_data *data)
{
	free_lk(data, 0);
	free_pipe(data, 0);
	free_all_data(data, 0);
}
