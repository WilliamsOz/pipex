/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 06:55:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 13:49:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

t_data	*is_there_here_doc(t_data *data, char *av1, char *av2, int ac)
{
	if (ft_strcmp(av1, "here_doc") == 1)
	{
		data->limiter = av2;
		data->is_there_here_doc = 1;
	}
	else
		data->is_there_here_doc = 0;
	if ((BONUS == 0 && data->is_there_here_doc == 1)
		|| (data->is_there_here_doc == 1 && ac < 6))
	{
		if (BONUS == 0 && data->is_there_here_doc == 1)
			ft_putstr("Here_doc found without having compiled bonus before\n");
		else
			ft_putstr("LIMITER is missing\n");
		close_pipex_fd();
		free_data(data);
		exit (errno);
	}
	return (data);
}
