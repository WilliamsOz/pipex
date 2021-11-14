/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:33:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/12 14:38:30 by wiozsert         ###   ########.fr       */
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

typedef struct s_data
{
    char        *path;
}               t_data;

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

#define PRINTS(x) printf("%s\n", x);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

int	    ft_strlen(char *str);
void    ft_putstr(char *str);

#endif