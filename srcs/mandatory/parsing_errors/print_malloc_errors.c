/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_malloc_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:40:43 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 14:02:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	data_cmd_malloc_failed(t_data *data)
{
	ft_putstr("Data cmd malloc has failed\n");
	free_data(data);
	close_pipex_fd();
	exit (errno);
}

void	data_malloc_failed(void)
{
	ft_putstr("Data malloc has failed\n");
	close_pipex_fd();
	exit (errno);
}

void	splitted_path_malloc_failed(t_data *data)
{
	ft_putstr("Splitted path data has failed\n");
	free_data(data);
	close_pipex_fd();
	exit (errno);
}

void	malloc_inside_splitted_path_failed(t_data *data, int count)
{
	ft_putstr("Malloc inside splitted path data has failed\n");
	while (count >= 0)
	{
		free(data->splited_path[count]);
		count--;
	}
	free(data->splited_path);
	free_data(data);
	close_pipex_fd();
	exit (errno);
}

void	malloc_of_cmd_and_pathern_failed(t_data *data)
{
	ft_putstr("Malloc of strcat pathern and cmd has failed\n");
	free_all_data(data, 0);
	close_pipex_fd();
	exit (errno);
}
