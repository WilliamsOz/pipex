/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:33:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 13:34:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BONUS 0
# include "./pipex_structures.h"
# include "./pipex_bonus.h"

t_data	*is_there_here_doc(t_data *data, char *av1, char *av2, int ac);
void	last_cmd(t_data *data, t_lk_data *tmp, int count);
void	first_cmd(t_data *data, t_lk_data *tmp);
void	close_pipex_fd(void);
void	free_lk(t_data *data, int count);
void	destroy_data(t_data *data);
void	free_splited_path(t_data *data, int count);
void	pipe_opening_has_failed(t_data *data);
t_data	*get_cmd_and_flags(t_data *data, char *av, t_lk_data *tmp);
t_data	*prepare_data_lk(t_data *data, char **av, int i, int cmd);
char	*get_command_pathern(t_data *data, char *spt_path, char *cmd);
void	link_inside_data_lk_failed(t_data *data);
void	data_lk_malloc_failed(t_data *data);
t_data	*check_all_errors(char **av, char **env, t_data *data);
void	init_pipe_in_data_failed(t_data *data);
t_data	*prepare_data_pipe(t_data *data, int len);
t_data	*init_and_get_splitted_path(t_data *data);
t_data	*get_path(t_data *data, char **env, int i, int j);
t_data	*init_and_get_cmd(t_data *data, char **av, int count, int i);
void	free_data(t_data *data);
void	free_all_data(t_data *data, int count);
void	command_doesnt_exist(t_data *data, char *cmd, int ind);
void	path_env_modified(t_data *data);
void	there_is_no_command(t_data *data);
void	too_many_arguments(void);
void	not_enough_arguments(void);
void	execve_failed(t_data *data);
void	fork_failed(t_data *data);
void	malloc_pipe_in_data_failed(t_data *data, int count);
void	malloc_of_cmd_lk_failed(t_data *data, int count);
void	malloc_of_init_cmd_inside_lk_failed(t_data *data, int i);
void	malloc_of_cmd_and_pathern_failed(t_data *data);
void	malloc_inside_splitted_path_failed(t_data *data, int count);
void	splitted_path_malloc_failed(t_data *data);
void	data_malloc_failed(void);
void	data_cmd_malloc_failed(t_data *data);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_lst_size(t_lk_data *lk);

#endif