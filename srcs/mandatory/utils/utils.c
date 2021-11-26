/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:51:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 12:29:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static int	get_len(char *spt_path, char *cmd, int i)
{
	int	len;

	len = ft_strlen(spt_path);
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	len += i;
	return (len);
}

static char	*cpy_command_pathern(char *dest, char *spt_path, char *cmd, int i)
{
	int	j;

	while (spt_path[i] != '\0')
	{
		dest[i] = spt_path[i];
		i++;
	}
	j = 0;
	while (cmd[j] != '\0' && cmd[j] != ' ')
	{
		dest[i] = cmd[j];
		i++;
		j++;
	}
	return (dest);
}

char	*get_command_pathern(t_data *data, char *spt_path, char *cmd)
{
	char	*dest;
	int		len;

	len = get_len(spt_path, cmd, 0);
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		ft_putstr("Malloc of cmd pathern has failed\n");
		if (data->lk_data != NULL)
			free_lk(data, 0);
		free_all_data(data, 0);
		exit (errno);
	}
	dest[len] = '\0';
	dest = cpy_command_pathern(dest, spt_path, cmd, 0);
	return (dest);
}
