/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:24:00 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 16:10:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static char	*get_first_read(char *line, char *buffer)
{
	line = (char *)malloc(sizeof(char) * 2);
	if (line == NULL)
		return (NULL);
	line[0] = buffer[0];
	line[1] = '\0';
	return (line);
}

static char	*get_next_reads(char *line, char *buffer)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = line;
	len = ft_strlen(line);
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	line[len] = buffer[0];
	line[len + 1] = '\0';
	i = 0;
	while (tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char	buffer[1];
	int		eof;

	buffer[0] = '\0';
	eof = read(fd, buffer, 1);
	if (buffer[0] == '\n' || eof == 0)
		return (eof);
	if (eof > 0)
		*line = get_first_read(*line, buffer);
	if (*line == NULL && eof > 0)
		return (-1);
	while (eof > 0 && buffer[0] != '\n')
	{
		eof = read(fd, buffer, 1);
		if (buffer[0] == '\n' || eof == 0)
			return (eof);
		*line = get_next_reads(*line, buffer);
		if (*line == NULL)
			return (-1);
	}
	return (eof);
}
