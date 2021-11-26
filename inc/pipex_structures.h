/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:08:57 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/26 13:12:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTURES_H
# define PIPEX_STRUCTURES_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# define _GNU_SOURCE

typedef struct s_lk_data
{
	char				*path_cmd;
	char				**cmd;
	int					unknow_cmd;
	struct s_lk_data	*next;
}				t_lk_data;

typedef struct s_data
{
	int			is_there_here_doc;
	int			here_doc_pipe[2];
	char		*limiter;
	char		*path;
	char		**cmd;
	char		**splited_path;
	t_lk_data	*lk_data;
	char		**env;
	int			input_file;
	int			output_file;
	int			**pipe_fd;
	int			pipe_ret;
	pid_t		child_pid;
	int			status;
	int			pipe_opening;
}				t_data;

#endif