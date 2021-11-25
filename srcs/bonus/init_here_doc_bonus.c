/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_here_doc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:43:47 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 08:14:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

t_data	*bonus_open_in_out_files(t_data *data, char **av, int i)
{
	while (av[i + 1] != NULL)
		i++;
	if (data->is_there_here_doc == 0)
		data->input_file = open(av[1], O_RDWR);
	data->output_file = open(av[i], O_CREAT | O_RDWR | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (data);
}
