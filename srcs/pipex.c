/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/19 18:39:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipe_failed(t_data *data)
{
	ft_putstr("Pipe opening has failed\n");
	free_all_data(data, 0);
	exit (EXIT_FAILURE);
}

void	pipex(t_data *data, char **av, char **env)
{
	int		pipe_ret;
	int		pipe_fd[2]; //fd[0] == lecture && fd[1] == ecriture
	pid_t	son_pid;
	int		status;
	int		fd_file[2];

	fd_file[0] = open(av[1], O_RDWR);
	fd_file[1] = open(av[4], O_RDWR);
	pipe_ret = pipe(pipe_fd);
	if (pipe_ret == -1)
		pipe_failed(data);
	son_pid = fork();
	if (son_pid == 0)
	{
		close(pipe_fd[0]); //lecture
		close(fd_file[1]);
		dup2(pipe_fd[1], STDOUT_FILENO); //ecriture
		dup2(fd_file[0], STDIN_FILENO);
		execve(data->lk_data->path_cmd, data->lk_data->cmd, env);
		PRINT("execve_failed\n");
	}
	else
	{
		close(fd_file[0]);
		close(pipe_fd[1]);
	}
	wait(&status);
	char buff[32];
	write(1, buff, read(pipe_fd[0], buff, 32));
}

// file1 cmd1 cmd2 ... cmdn file2

int	main(int ac, char **av, char **env) //proteger les mallocs de la lk
{
	t_data	*data;

	if (ac < 5)
		not_enough_arguments();
	data = NULL;
	data = check_all_errors(av, env, data);
	data = prepare_data_lk(data, av, 2, 0);
	pipex(data, av, env);
	free_all_data(data, 0);
	return (0);
}
