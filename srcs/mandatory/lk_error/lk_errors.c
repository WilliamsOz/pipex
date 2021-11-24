/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:18:41 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 17:18:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	data_lk_malloc_failed(t_data *data)
{
	ft_putstr("Malloc of data linked list has failed\n");
	free_all_data(data, 0);
	exit (EXIT_FAILURE);
}

void	link_inside_data_lk_failed(t_data *data)
{
	t_lk_data	*tmp;

	if (data->lk_data->next == NULL)
	{
		free(data->lk_data);
		data_lk_malloc_failed(data);
	}
	else
	{
		while (data->lk_data != NULL)
		{
			tmp = data->lk_data;
			data->lk_data = data->lk_data->next;
			free(tmp);
		}
	}
	ft_putstr("Malloc of some link in data linked list has failed\n");
	free_all_data(data, 0);
	exit (EXIT_FAILURE);
}

void	malloc_of_init_cmd_inside_lk_failed(t_data *data, int i)
{
	t_lk_data	*tmp;

	while (i >= 0)
	{
		tmp = data->lk_data;
		data->lk_data = data->lk_data->next;
		free(tmp->cmd[i]);
		free(tmp->path_cmd);
		free(tmp);
		i--;
	}
	free_all_data(data, 0);
	ft_putstr("Malloc of initialisation of data lk has failed\n");
	exit (EXIT_FAILURE);
}
