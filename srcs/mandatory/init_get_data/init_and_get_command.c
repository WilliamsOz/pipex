/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_get_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:38:05 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 14:16:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static t_data	*get_cmd(t_data *data, char **av, int count, int i)
{
	if (data->is_there_here_doc == 1)
		i++;
	while (av[i + 1] != NULL)
	{
		data->cmd[count] = av[i];
		i++;
		count++;
	}
	return (data);
}

t_data	*init_and_get_cmd(t_data *data, char **av, int count, int i)
{
	if (data->is_there_here_doc == 1)
		i++;
	while (av[i + 1] != NULL)
	{
		count++;
		i++;
	}
	if (count == 0)
		there_is_no_command(data);
	data->cmd = NULL;
	data->cmd = (char **)malloc(sizeof(char *) * (count + 1));
	data->cmd_nbr = count;
	printf("%d\n", data->cmd_nbr);
	if (data->cmd == NULL)
		data_cmd_malloc_failed(data);
	data->cmd[count] = NULL;
	data = get_cmd(data, av, 0, 2);
	return (data);
}
