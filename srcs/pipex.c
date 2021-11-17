/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/17 19:07:35 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
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

// static void	check_cmd(t_data *data, int i)
// {
// 	while (data->cmd[i] != NULL)
// 	{
// 		if (data->cmd[i][0] == '/')
// 		{
			
// 		}
// 	}
// 	//acces en chemin absolu
// 	//aussi si ya un espace comme "ls -l"
// 	//split le path et rajouter un '/' et check si les commandes existe
// }

static char	*get_command_pathern(char *s1, char *s2, int i, int j)
{
	char	*dest;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		ft_putstr("Malloc of pathern has failed\n");
		return (NULL);
	}
	dest[len] = '\0';
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	return (dest);
}

void	verify_cmd(t_data *data, int cmd, int spath, int ind)
{
	char	*tmp;

	while (data->cmd[cmd] != NULL)
	{
		ind = -1;
		while (data->splited_path[spath] != NULL && ind == -1)
		{
			tmp = NULL;
			tmp = get_command_pathern(data->splited_path[spath],
				data->cmd[cmd], 0, 0);
			if (tmp == NULL)
			{
				free_all_data(data, 0);
				exit (EXIT_FAILURE);
			}
			ind = access(tmp, F_OK | X_OK);
			free(tmp);
			PRINTD(ind)
			spath++;
		}
		// if (ind == -1)
			// command_doesnt_exist();
		spath = 0;
		cmd++;
	}
}

t_data	*check_command(t_data *data, char **av)
{
	data = init_and_get_cmd(data, av, 0, 2);
	data = init_and_get_splitted_path(data);
	verify_cmd(data, 0, 0, -1);
	return (data);
}

t_data	*check_all_errors(char **av, char **env, t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		data_malloc_failed();
	data = get_path(data, env, 0, 0);
	if (data->path == NULL)
		path_env_modified(data);
	data = check_command(data, av);
	return (data);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	if (ac < 5)
	{
		ft_putstr("There is not enough argument\n");
		exit (EXIT_FAILURE);
	}
	data = NULL;
	data = check_all_errors(av, env, data);
	free_all_data(data, 0);
	return (0);
}
