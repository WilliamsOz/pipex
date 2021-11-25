/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:54:53 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 19:55:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

t_data	*get_path(t_data *data, char **env, int i, int j)
{
	while (env[i] != NULL)
	{
		while (env[i][j] != '\0')
		{
			if (env[i][j] == 'P' && env[i][j + 1] == 'A'
				&& env[i][j + 2] == 'T' && env[i][j + 3] == 'H'
				&& env[i][j + 4] == '=' && env[i][j + 5] != '\0')
				{
					data->path = env[i];
					return (data);
				}
			i++;
		}
	}
	data->path = NULL;
	return (data);
}
