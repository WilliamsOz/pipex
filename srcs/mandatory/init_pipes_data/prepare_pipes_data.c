/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_pipes_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:38:32 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 07:31:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

t_data	*prepare_data_pipe(t_data *data, int len)
{
	while (data->cmd[len + 1] != NULL)
		len++;
	data->pipe_fd = (int **)malloc(sizeof(int *) * (len + 1));
	if (data->pipe_fd == NULL)
		init_pipe_in_data_failed(data);
	data->pipe_fd[len] = NULL;
	len = 0;
	while (data->cmd[len + 1] != NULL)
	{
		data->pipe_fd[len] = (int *)malloc(sizeof(int) * 2);
		if (data->pipe_fd[len] == NULL)
			malloc_pipe_in_data_failed(data, len -1);
		data->pipe_opening = pipe(data->pipe_fd[len]);
		if (data->pipe_opening == -1)
			pipe_opening_has_failed(data);
		len++;
	}
	return (data);
}
