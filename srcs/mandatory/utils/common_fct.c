/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:59:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 12:01:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/pipex.h"

void	ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);
}

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
