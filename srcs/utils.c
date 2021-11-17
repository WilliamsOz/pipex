/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:51:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/17 18:22:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
