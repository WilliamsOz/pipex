/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:16:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 14:27:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static int	is_there_flags(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	if (cmd[i] == ' ')
	{
		while (cmd[i] == ' ')
			i++;
		if (cmd[i] != '\0')
			return (1);
	}
	return (0);
}

static char	*get_only_cmd(t_data *data, char *cmd, int i, int len)
{
	char	*tmp;

	while (cmd[len] != ' ')
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
	{
		free_all_data(data, 0);
		ft_putstr("Malloc of cmd without path has failed\n");
		exit (errno);
	}
	tmp[len] = '\0';
	while (cmd[i] != ' ')
	{
		tmp[i] = cmd[i];
		i++;
	}
	return (tmp);
}

static int	check_absolute_path_access(t_data *data, int cmd)
{
	char	*tmp;
	int		ind;

	if (is_there_flags(data->cmd[cmd]) == 1)
	{
		tmp = get_only_cmd(data, data->cmd[cmd], 0, 0);
		ind = access(tmp, F_OK | X_OK);
		if (ind == -1)
			command_doesnt_exist(data, tmp, cmd);
		free(tmp);
	}
	else
	{
		ind = access(data->cmd[cmd], F_OK | X_OK);
		if (ind == -1)
			command_doesnt_exist(data, data->cmd[cmd], cmd);
	}
	ind = 0;
	return (ind);
}

static void	verify_cmd(t_data *data, int cmd, int spath, int ind)
{
	char	*tmp;

	while (cmd < data->cmd_nbr)
	{
		ind = -1;
		if (data->cmd[cmd][0] == '/')
			ind = check_absolute_path_access(data, cmd);
		while (data->splited_path[spath] != NULL && ind == -1)
		{
			tmp = NULL;
			tmp = get_command_pathern(data, data->splited_path[spath],
					data->cmd[cmd]);
			if (tmp == NULL)
				malloc_of_cmd_and_pathern_failed(data);
			ind = access(tmp, F_OK | X_OK);
			free(tmp);
			spath++;
		}
		if (ind == -1)
			command_doesnt_exist(data, data->cmd[cmd], cmd);
		spath = 0;
		cmd++;
	}
}

t_data	*check_all_errors(char **av, char **env, t_data *data)
{
	data->cmd_nbr = 0;
	data = get_path(data, env, 0, 0);
	if (data->path == NULL)
		path_env_modified(data);
	data = init_and_get_cmd(data, av, 0, 2);
	data = init_and_get_splitted_path(data);
	verify_cmd(data, 0, 0, -1);
	return (data);
}
