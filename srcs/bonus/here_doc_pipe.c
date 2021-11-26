/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 06:38:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 13:53:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	here_doc_pipe(t_data *data, int eof)
{
	char	*line;

	data->pipe_opening = pipe(data->here_doc_pipe);
	if (data->pipe_opening == -1)
		pipe_opening_has_failed(data);
	while (eof == -1)
	{
		line = NULL;
		write(1, ">", 1);
		eof = get_next_line(0, &line);
		if (eof > 0)
		{
			if (line != NULL && ft_strcmp(line, data->limiter) == 1)
			{
				if (line != NULL)
					free(line);
				break ;
			}
			eof = -1;
		}
		write(data->here_doc_pipe[1], line, ft_strlen(line));
		write(data->here_doc_pipe[1], "\n", 1);
		free(line);
	}
	close(data->here_doc_pipe[1]);
}
