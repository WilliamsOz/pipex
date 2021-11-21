/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/20 17:29:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	pipe_opening_has_failed(t_data *data)
{
	ft_putstr("Pipe opening has failed\n");
	destroy_data(data);
	exit (EXIT_FAILURE);
}
