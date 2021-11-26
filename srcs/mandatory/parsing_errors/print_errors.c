/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:49:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 13:59:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	not_enough_arguments(void)
{
	ft_putstr("There is not enough argument\n");
	close_pipex_fd();
	exit (errno);
}

void	path_env_modified(t_data *data)
{
	ft_putstr("The path environment variable has been changed\n");
	free_data(data);
	close_pipex_fd();
	exit (errno);
}

void	there_is_no_command(t_data *data)
{
	ft_putstr("There is no command\n");
	free_data(data);
	close_pipex_fd();
	exit (errno);
}

void	command_doesnt_exist(t_data *data, char *cmd, int ind)
{
	if (data->input_file == -1 && ind == 0)
		return ;
	write(2, cmd, ft_strlen(cmd));
	write(2, ":command not found\n", 19);
}

void	too_many_arguments(void)
{
	ft_putstr("Too many arguments\n");
	close_pipex_fd();
	exit (errno);
}
