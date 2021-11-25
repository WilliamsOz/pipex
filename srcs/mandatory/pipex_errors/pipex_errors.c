/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	pipe_opening_has_failed(t_data *data)
{
	ft_putstr("Pipe opening has failed\n");
	destroy_data(data);
	close_pipex_fd();
	exit (EXIT_FAILURE);
}

void	init_pipe_in_data_failed(t_data *data)
{
	ft_putstr("Initialisation of pipe inside data has failed\n");
	destroy_data(data);
	close_pipex_fd();
	exit (EXIT_FAILURE);
}

void	malloc_pipe_in_data_failed(t_data *data, int count)
{
	ft_putstr("Malloc of pipe inside data has failed\n");
	while (count >= 0)
	{
		free(data->pipe_fd[count]);
		count--;
	}
	free(data->pipe_fd);
	destroy_data(data);
	close_pipex_fd();
	exit (EXIT_FAILURE);
}

void	fork_failed(t_data *data)
{
	ft_putstr("Fork has failed\n");
	destroy_data(data);
	close_pipex_fd();
	exit (EXIT_FAILURE);
}

void	execve_failed(t_data *data)
{
	destroy_data(data);
	close_pipex_fd();
	exit (EXIT_FAILURE);
}
