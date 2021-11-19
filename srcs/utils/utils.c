/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:51:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/19 14:37:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);
}

char	*get_command_pathern(char *s1, char *cmd, int i, int j)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1);
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	len += i;
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (cmd[j] != '\0' && cmd[j] != ' ')
	{
		dest[i] = cmd[j];
		i++;
		j++;
	}
	return (dest);
}