/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 06:55:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 13:31:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

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
