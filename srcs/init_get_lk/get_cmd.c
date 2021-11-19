/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:24:26 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/19 18:41:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static char		*cpy_cmd_and_flags(char *cmd, char *av, int i, int cpy)
{
	while (i > 0 && av[i] != ' ')
		i--;
	if (av[i] == ' ' && i > 0)
		i++;
	while (av[i] != '\0' && av[i] != ' ')
	{
		cmd[cpy] = av[i];
		i++;
		cpy++;
	}
	return (cmd);
}

// void	malloc_of_cmd_lk_failed(t_data *data, int count, t_lk_data *lk, int i)
// {
	
// }

static t_data	*init_get_lk_cmd(t_data *data, char *av, int i, int len)
{
	int	count;

	count = 0;
	while (av[i] != '\0')
	{
		while (av[i] != '\0' && av[i] != ' ')
		{
			if (av[i] != ' ')
				len++;
			i++;
		}
		data->lk_data->cmd[count] = (char *)malloc(sizeof(char) * (len + 1));
		// if (data->t_lk_data->cmd[count] == NULL)
			// malloc_of_cmd_lk_failed(data, count, data->lk_data->cmd);
		data->lk_data->cmd[count][len] = '\0';
		data->lk_data->cmd[count] = 
		cpy_cmd_and_flags(data->lk_data->cmd[count], av, i -1, 0);
		while (av[i] != '\0' && av[i] == ' ')
			i++;
		len = 0;
		count++;
	}
	return (data);
}

t_data	*get_cmd_and_flags(t_data *data, char *av)
{
	data = init_get_lk_cmd(data, av, 0, 0); //perte de l'adresse de la lk, separation a faire pour copier
	return (data);
}
