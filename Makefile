# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 13:15:41 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/17 18:19:18 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

#srcs
FILESC = $(shell find ./srcs/ -type f)
OBJS = pipex.o ft_putstr.o ft_strlen.o get_path.o init_and_get_command.o \
init_and_get_splitted_path.o print_errors.o print_malloc_errors.o utils.o

#bonus

all : $(NAME)

$(NAME) : $(FILESC)
	@mkdir -p obj
	@cc $(FLAGS) -c $(FILESC)
	@cc $(FLAGS) $(OBJS) -o $(NAME)
	@mv $(OBJS) ./obj

clean :
	@rm -Rf ./obj

fclean : clean
	@rm -Rf $(NAME)

re : fclean all