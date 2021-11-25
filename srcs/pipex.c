/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 01:59:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_data	*open_in_out_files(t_data *data, char **av, int i)
{
	while (av[i + 1] != NULL)
		i++;
	data->input_file = open(av[1], O_RDWR);
	data->output_file = open(av[i], O_CREAT | O_RDWR | O_TRUNC);
	return (data);
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
			if (line != NULL)
				free(line);
		}
	}
}

void	pipex(t_data *data, int count)
{
	t_lk_data	*tmp;

	tmp = data->lk_data;
	if (data->is_there_here_doc == 1)
		here_doc_pipe(data, -1);
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
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		data_malloc_failed();
	data = is_there_here_doc(data, av[1], av[2]);
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	data = prepare_data_pipe(data, 0);
	if (BONUS == 1)
		data = bonus_open_in_out_files(data, av, 0);
	else
		data = open_in_out_files(data, av, 0);
	data->env = env;
	pipex(data, 0);
	destroy_data(data);
	return (0);
}
