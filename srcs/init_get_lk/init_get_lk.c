/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_get_lk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:58:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/20 13:28:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static t_data	*init_data_lk(t_data *data, int len)
{
	t_lk_data	*tmp;
	t_lk_data	*new_lk;

	while (data->cmd[len] != NULL)
		len++;
	data->lk_data = (t_lk_data *)malloc(sizeof(t_lk_data));
	if (data->lk_data == NULL)
		data_lk_malloc_failed(data);
	data->lk_data->next = NULL;
	len -= 1;
	while (len > 0)
	{
		new_lk = (t_lk_data *)malloc(sizeof(t_lk_data));
		if (new_lk == NULL)
			link_inside_data_lk_failed(data);
		new_lk->next = NULL;
		tmp = data->lk_data;
		while (tmp ->next != NULL)
			tmp = tmp->next;
		tmp->next = new_lk;
		len -= 1;
	}
	return (data);
}

static char	*get_direct_path(t_data *data, int cmd, int path)
{
	char	*tmp;
	int		ind;

	ind = -1;
	tmp = NULL;
	while (ind == -1)
	{
		tmp = get_command_pathern(data->splited_path[path],
			data->cmd[cmd], 0, 0);
		ind = access(tmp, F_OK | X_OK);
		if (ind == -1)
		{
			free(tmp);
			path++;
		}
	}
	return (tmp);
}

static int	get_size_cmd_with_flags(char *av, int i)
{
	int	len;

	len = 1;
	while (av[i] != '\0')
	{
		if (av[i] == ' ' && av[i + 1] != '\0')
			len++;
		i++;
	}
	return (len);
}

t_data	*prepare_data_lk(t_data *data, char **av, int i, int cmd)
{
	t_lk_data	*tmp;
	int			len;

	data = init_data_lk(data, 0);
	tmp = data->lk_data;
	while (av[i + 1] != NULL)
	{
		len = get_size_cmd_with_flags(av[i], 0);
		tmp->cmd = (char **)malloc(sizeof(char *) * (len + 1));
		if (tmp->cmd == NULL)
			malloc_of_init_cmd_inside_lk_failed(data, i - 3);
		tmp->cmd[len] = NULL;
		data = get_cmd_and_flags(data, av[i], tmp);
		tmp->path_cmd = get_direct_path(data, cmd, 0);
		tmp = tmp->next;
		i++;
		cmd++;
	}
	data->fd_file[0] = open(av[1], O_RDWR);
	data->fd_file[1] = open(av[i], O_RDWR);
	return (data);
}
