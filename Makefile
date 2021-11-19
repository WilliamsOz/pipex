# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 13:15:41 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/19 12:29:32 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

#srcs
FILESC = $(shell find ./srcs/ -type f) #definir les .c en brut pour wilcard
OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

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