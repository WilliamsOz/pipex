/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/25 01:27:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./pipex_structures.h"

int 	ft_strcmp(char *s1, char *s2);
int 	get_next_line(int fd, char **line);
t_data	*bonus_open_in_out_files(t_data *data, char **av, int i);
t_data	*is_there_here_doc(t_data *data, char *av1, char *av2);
void	execve_failed(t_data *data);
void	fork_failed(t_data *data);
t_lk_data	*treat_mid_cmds(t_data *data, t_lk_data *tmp, int *ptr_count);

#endif