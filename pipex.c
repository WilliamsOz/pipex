/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/14 14:52:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
/*
avec access(const char *pathname, int mode) :
checker si les commandes en argument existe avec access :
Si access == 0, c'est ok
si access == -1, c'est pas ok
mode :
F_OK : le fichier existe | R_OK lecture | W_OK ecriture | X_OK l'execution



Error case :

._"export -n PATH" (retire le PATH de l'env) :
pas de PATH, les commandes marche quand meme ?

._"unset PATH" => print "bash: ls: No such file or directory" && return (0);
*/

void	free_data(t_data *data)
{
	free(data);
	data = NULL;
}

static t_data	*get_path(t_data *data, char **env, int i, int j)
{
	while (env[i] != NULL)
	{
		while (env[i][j] != '\0')
		{
			if (env[i][j] == 'P' && env[i][j + 1] == 'A'
				&& env[i][j + 2] == 'T' && env[i][j + 3] == 'H'
				&& env[i][j + 4] == '=' && env[i][j + 5] != '\0')
				{
					data->path = env[i];
					return (data);
				}
			i++;
		}
	}
	data->path = NULL;
	return (data);
}

static int	check_if_command_exist(char **av, char *path)
{
	//acces en chemin absolu
	//aussi si ya un espace comme "ls -l"
	//split le path et rajouter un '/' et check si les commandes existe
}

int	check_all_errors(int ac, char **av, char **env)
{
	t_data	*data;

	data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		ft_putstr("Data malloc has failed\n");
		exit (EXIT_FAILURE);
	}
	data = get_path(data, env, 0, 0);
	if (data->path == NULL)
	{
		free_data(data);
		ft_putstr("The path environment variable has been changed\n");
		return (1);
	}
	if (check_if_command_exist(av, data->path) == -1)
	{
		free_data(data);
		ft_putstr("Some commands are incorrect\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		ft_putstr("There is not enough argument\n");
		exit (EXIT_FAILURE);
	}
	if (check_all_errors(ac, av, env) == 1)
		return (0);
	return (0);
}
