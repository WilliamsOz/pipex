/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 16:14:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./pipex_structure.h"

void	fork_failed(t_data *data);
void	treat_mid_cmds(t_data *data, t_lk_data *tmp, int *ptr_count);

#endif