/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:16:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/21 15:19:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static int	check_absolute_path_access(t_data *data, int cmd)
{
	int		ind;

	ind = access(data->cmd[cmd], F_OK | X_OK);
	if (ind == -1)
		command_doesnt_exist(data, data->cmd[cmd]);
	return (ind);
}

static void	verify_cmd(t_data *data, int cmd, int spath, int ind)
{
	char	*tmp;

	while (data->cmd[cmd] != NULL)
	{
		ind = -1;
		if (data->cmd[cmd][0] == '/')
			ind = check_absolute_path_access(data, cmd);
		while (data->splited_path[spath] != NULL && ind == -1)
		{
			tmp = NULL;
			tmp = get_command_pathern(data->splited_path[spath],
				data->cmd[cmd], 0, 0);
			if (tmp == NULL)
				malloc_of_cmd_and_pathern_failed(data);
			ind = access(tmp, F_OK | X_OK);
			free(tmp);
			spath++;
		}
		if (ind == -1)
			command_doesnt_exist(data, data->cmd[cmd]);
		spath = 0;
		cmd++;
	}
}

t_data	*check_all_errors(char **av, char **env, t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		data_malloc_failed();
	data = get_path(data, env, 0, 0);
	if (data->path == NULL)
		path_env_modified(data);
	data = init_and_get_cmd(data, av, 0, 2);
	data = init_and_get_splitted_path(data);
	verify_cmd(data, 0, 0, -1);
	return (data);
}
