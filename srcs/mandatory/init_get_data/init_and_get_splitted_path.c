/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_get_splitted_path.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:43:30 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 17:18:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static t_data	*init_splitted_path(t_data *data, int count, int i)
{
	while (data->path[i] != '\0')
	{
		if (data->path[i] == ':')
			count++;
		i++;
	}
	count += 1;
	data->splited_path = NULL;
	data->splited_path = (char **)malloc(sizeof(char *) * (count + 1));
	if (data->splited_path == NULL)
		splitted_path_malloc_failed(data);
	data->splited_path[count] = NULL;
	return (data);
}

t_data	*cpy_path_into_spath(t_data *data, int i, int cpy, int count)
{
	while (data->path[i - 1] != ':' && data->path[i - 1] != '=')
		i--;
	while (data->path[i] != '\0' && data->path[i] != ':')
	{
		data->splited_path[count][cpy] = data->path[i];
		i++;
		cpy++;
	}
	return (data);
}

static t_data	*get_splitted_path(t_data *data, int i, int len, int count)
{
	while (data->path[i - 1] != '=')
		i++;
	while (data->path[i] != '\0')
	{
		while (data->path[i] != '\0' && data->path[i] != ':')
		{
			i++;
			len++;
		}
		data->splited_path[count] = NULL;
		data->splited_path[count] = (char *)malloc(sizeof(char) * (len + 2));
		if (data->splited_path == NULL)
			malloc_inside_splitted_path_failed(data, count - 1);
		data->splited_path[count][len + 1] = '\0';
		data->splited_path[count][len] = '/';
		data = cpy_path_into_spath(data, i - 1, 0, count);
		if (data->path[i] != '\0')
			i++;
		count++;
		len = 0;
	}
	return (data);
}

t_data	*init_and_get_splitted_path(t_data *data)
{
	data = init_splitted_path(data, 0, 0);
	data = get_splitted_path(data, 0, 0, 0);
	return (data);
}
