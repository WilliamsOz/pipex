/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 18:34:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_data *data, int count)
{
	t_lk_data	*tmp;

	tmp = data->lk_data;
	first_cmd(data, tmp);
	tmp = tmp->next;
	count++;
	if (BONUS == 1 && data->cmd[count + 1] != NULL)
		tmp = treat_mid_cmds(data, tmp, &count);
	last_cmd(data, tmp, count);
	close_pipex_fd();
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	if (BONUS == 0 && ac > 5)
		too_many_arguments();
	data = NULL;
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	data->env = env;
	pipex(data, 0);
	destroy_data(data);
	return (0);
}
