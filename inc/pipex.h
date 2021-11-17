/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:33:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/17 18:34:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

# include <stdio.h> //perror
//void perror(const char *s); => Afficher un message d'erreur système  

# include <string.h> //strerror
//char *strerror(int errnum); => Obtenir le libellé d'un numéro d'erreur.

#include <errno.h> // errno

typedef struct s_data
{
	char	*path;
	char	**cmd;
	char	**splited_path;
}               t_data;

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

#define D printf("ICI\n");
#define PRINTS(x) printf("%s\n", x);
#define PRINTD(x) printf("%d\n", x);
#define PRINTC(x) printf("%c\n", x);
#define PRINTP(x) printf("%p\n", x);
#define ex exit (EXIT_FAILURE);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

t_data	*init_and_get_splitted_path(t_data *data);
t_data	*get_path(t_data *data, char **env, int i, int j);
t_data	*init_and_get_cmd(t_data *data, char **av, int count, int i);
void	free_data(t_data *data);
void	free_all_data(t_data *data, int count);
void	path_env_modified(t_data *data);
void	there_is_no_command(t_data *data);
void	malloc_inside_splitted_path_failed(t_data *data, int count);
void	splitted_path_malloc_failed(t_data *data);
void	data_malloc_failed();
void	data_cmd_malloc_failed(t_data *data);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#endif