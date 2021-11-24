/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:33:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 17:03:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

#define D printf("ICI\n");
#define PRINT(x) printf(x);
#define PRINTS(x) printf("%s\n", x);
#define PRINTD(x) printf("%d\n", x);
#define PRINTC(x) printf("%c\n", x);
#define PRINTP(x) printf("%p\n", x);
#define ex exit (EXIT_FAILURE);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

# define BONUS 0
# include "./pipex_structure.h"
# include "./pipex_bonus.h"

void	last_cmd(t_data *data, t_lk_data *tmp, int count);
void	first_cmd(t_data *data, t_lk_data *tmp);
void	close_pipex_fd();
void	free_lk(t_data *data, int count);
void	destroy_data(t_data *data);
void	free_splited_path(t_data *data, int count);
void	pipe_opening_has_failed(t_data *data);
t_data	*get_cmd_and_flags(t_data *data, char *av, t_lk_data *tmp);
t_data	*prepare_data_lk(t_data *data, char **av, int i, int cmd);
char	*get_command_pathern(char *s1, char *cmd, int i, int j);
void	link_inside_data_lk_failed(t_data *data);
void	data_lk_malloc_failed(t_data *data);
t_data	*check_all_errors(char **av, char **env, t_data *data);
void	init_pipe_in_data_failed(t_data *data);
t_data	*init_and_get_splitted_path(t_data *data);
t_data	*get_path(t_data *data, char **env, int i, int j);
t_data	*init_and_get_cmd(t_data *data, char **av, int count, int i);
void	free_data(t_data *data);
void	free_all_data(t_data *data, int count);
void	command_doesnt_exist(t_data *data, char *cmd);
void	path_env_modified(t_data *data);
void	there_is_no_command(t_data *data);
void	not_enough_arguments();
void	execve_failed(t_data *data);
void	fork_failed(t_data *data);
void	malloc_pipe_in_data_failed(t_data *data, int count);
void	malloc_of_cmd_lk_failed(t_data *data, int count);
void	malloc_of_init_cmd_inside_lk_failed(t_data *data, int i);
void	malloc_of_cmd_and_pathern_failed(t_data *data);
void	malloc_inside_splitted_path_failed(t_data *data, int count);
void	splitted_path_malloc_failed(t_data *data);
void	data_malloc_failed();
void	data_cmd_malloc_failed(t_data *data);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_lst_size(t_lk_data *lk);

#endif