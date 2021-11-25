/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:51:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 19:52:37 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	close_pipex_fd()
{
	close(0);
	close(1);
	close(2);
}

int		ft_lst_size(t_lk_data *lk)
{
	t_lk_data	*tmp;
	int			len;

	len = 0;
	tmp = lk;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

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

char	*get_command_pathern(char *spt_path, char *cmd, int i, int j)
{
	char	*dest;
	int		len;

	len = ft_strlen(spt_path);
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	len += i;
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	i = 0;
	while (spt_path[i] != '\0')
	{
		dest[i] = spt_path[i];
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
