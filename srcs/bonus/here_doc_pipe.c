/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 06:38:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 17:00:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

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

void	here_doc_pipe(t_data *data, int eof)
{
	char	*line;

	data->pipe_opening = pipe(data->here_doc_pipe);
	if (data->pipe_opening == -1)
		pipe_opening_has_failed(data);
	dup2(data->here_doc_pipe[1], STDIN_FILENO);
	while (eof == -1)
	{
		line = NULL;
		eof = get_next_line(1, &line);
		if (eof > 0)
		{
			if (line != NULL && ft_strcmp(line, data->limiter) == 1)
				eof = 0;
			else
				eof = -1;
		}
		if (line != NULL)
			free(line);
	}
}
