/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 12:33:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_data	*open_in_out_files(t_data *data, char **av, int i)
{
	while (av[i + 1] != NULL)
		i++;
	data->input_file = open(av[1], O_RDWR);
	if (data->input_file == -1)
		perror(strerror(errno));
	data->output_file = open(av[i], O_CREAT | O_RDWR | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (data);
}

void	pipex(t_data *data, int count)
{
	t_lk_data	*tmp;

	tmp = data->lk_data;
	if (BONUS == 1 && data->is_there_here_doc == 1)
		here_doc_pipe(data, -1);
	first_cmd(data, tmp);
	tmp = tmp->next;
	count++;
	if (BONUS == 1 && data->cmd[count + 1] != NULL)
		tmp = treat_mid_cmds(data, tmp, &count);
	last_cmd(data, tmp, count);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	if (BONUS == 0 && ac > 5)
		too_many_arguments();
	data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	data = is_there_here_doc(data, av[1], av[2], ac);
	if (data == NULL)
		data_malloc_failed();
	if (BONUS == 1)
		data = bonus_open_in_out_files(data, av, 0);
	else
		data = open_in_out_files(data, av, 0);
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	data = prepare_data_pipe(data, 0);
	data->env = env;
	pipex(data, 0);
	destroy_data(data);
	close_pipex_fd();
	return (errno);
}
