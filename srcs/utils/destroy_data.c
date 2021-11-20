/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:21:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/20 13:07:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

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
