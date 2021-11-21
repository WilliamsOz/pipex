/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:33:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/21 15:34:11 by wiozsert         ###   ########.fr       */
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
// perror(strerror(errno));

#include <errno.h> // errno

typedef struct s_lk_data
{
	char				*path_cmd;
	char				**cmd;
	struct s_lk_data	*next;
}				t_lk_data;

typedef struct s_data
{
	char		*path; //not mal
	char		**cmd; //**cmd mal not cmd[count]
	char		**splited_path; //mal
	t_lk_data	*lk_data; //mal
	char		**env; //not_mal
	int			input_file;
	int			output_file;
	int			pipe_fd[2];
	int			pipe_ret;
	pid_t		child_pid;
	int			status;
}				t_data;

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

#define D printf("ICI\n");
#define PRINT(x) printf(x);
#define PRINTS(x) printf("%s\n", x);
#define PRINTD(x) printf("%d\n", x);
#define PRINTC(x) printf("%c\n", x);
#define PRINTP(x) printf("%p\n", x);
#define ex exit (EXIT_FAILURE);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

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
t_data	*init_and_get_splitted_path(t_data *data);
t_data	*get_path(t_data *data, char **env, int i, int j);
t_data	*init_and_get_cmd(t_data *data, char **av, int count, int i);
void	free_data(t_data *data);
void	free_all_data(t_data *data, int count);
void	command_doesnt_exist(t_data *data, char *cmd);
void	path_env_modified(t_data *data);
void	there_is_no_command(t_data *data);
void	not_enough_arguments();
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