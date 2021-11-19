/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:49:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/19 14:18:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	not_enough_arguments()
{
	ft_putstr("There is not enough argument\n");
	exit (EXIT_FAILURE);
}

void	path_env_modified(t_data *data)
{
	free_data(data);
	ft_putstr("The path environment variable has been changed\n");
	exit (EXIT_FAILURE);
}

void	there_is_no_command(t_data *data)
{
	ft_putstr("There is no command\n");
	free_data(data);
	exit (EXIT_FAILURE);
}

void	command_doesnt_exist(t_data *data, char *cmd)
{
	ft_putstr(cmd);
	ft_putstr(" command does not exist\n");
	free_all_data(data, 0);
	exit (EXIT_FAILURE);
}
