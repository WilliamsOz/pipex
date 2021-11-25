/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:24:26 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 17:47:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

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

void	malloc_of_cmd_lk_failed(t_data *data, int count)
{
	t_lk_data	*tmp;

	tmp = data->lk_data;
	while (count >= 0)
	{
		free(tmp->cmd[count]);
		count--;
		tmp = tmp->next;
	}
	count = ft_lst_size(data->lk_data) - 1;
	while (count >= 0)
	{
		tmp = data->lk_data;
		data->lk_data = data->lk_data->next;
		free(tmp->cmd[count]);
		free(tmp->path_cmd);
		free(tmp);
		count--;
	}
	free_all_data(data, 0);
	ft_putstr("Malloc of initialisation of cmd inside data lk has failed\n");
	exit (EXIT_FAILURE);
}

static t_data	*get_lk_cmd(t_data *data, t_lk_data *tmp_data, char *av, int i)
{
	int		len;
	int		count;

	count = 0;
	len = 0;
	while (av[i] != '\0')
	{
		while (av[i] != '\0' && av[i] != ' ')
		{
			len++;
			i++;
		}
		tmp_data->cmd[count] = (char *)malloc(sizeof(char) * (len + 1));
		if (tmp_data->cmd[count] == NULL)
			malloc_of_cmd_lk_failed(data, count - 1);
		tmp_data->cmd[count][len] = '\0';
		tmp_data->cmd[count] = 
			cpy_cmd_and_flags(tmp_data->cmd[count], av, i -1, 0);
		while (av[i] != '\0' && av[i] == ' ')
			i++;
		len = 0;
		count++;
	}
	return (data);
}

t_data	*get_cmd_and_flags(t_data *data, char *av, t_lk_data *tmp)
{
	data = get_lk_cmd(data, tmp, av, 0);
	return (data);
}
