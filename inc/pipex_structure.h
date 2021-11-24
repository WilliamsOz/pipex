/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:08:57 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/24 16:58:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTURE_H
# define PIPEX_STRUCTURE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h> //perror
//void perror(const char *s); => Afficher un message d'erreur système  
# include <string.h> //strerror
//char *strerror(int errnum); => Obtenir le libellé d'un numéro d'erreur.
// perror(strerror(errno));
# include <errno.h> // errno
# include "./pipex_structure.h"

typedef struct s_lk_data
{
	char				*path_cmd;
	char				**cmd;
	struct s_lk_data	*next;
}				t_lk_data;

typedef struct s_data
{
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
}				t_data;

#endif