/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 14:18:06 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./pipex_structures.h"

void		ft_putstr(char *str);
int			get_next_line(int fd, char **line);
void		here_doc_pipe(t_data *data, int eof);
t_data		*bonus_open_in_out_files(t_data *data, char **av, int i);
void		execve_failed(t_data *data);
void		fork_failed(t_data *data);
t_lk_data	*treat_mid_cmds(t_data *data, t_lk_data *tmp, int *ptr_count);
void		pipe_opening_has_failed(t_data *data);
int			ft_strcmp(char *s1, char *s2);

#endif