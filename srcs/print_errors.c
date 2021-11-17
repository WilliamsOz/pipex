/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:49:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/17 16:47:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
