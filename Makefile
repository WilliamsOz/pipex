# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 13:15:41 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/24 17:05:05 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
uname = 

#srcs
FILESC = $(shell find ./srcs/ -type f) #definir les .c en brut pour wilcard
OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

#bonus
BONUSFILESC = run_mid_cmds_bonus.c
BONUSOBJS = $(addsuffix .o, $(notdir $(basename $(BONUSFILESC))))


all : $(NAME)

$(NAME) : $(FILESC)
	@sed -i "s/# define BONUS 1/# define BONUS 0/g" ./inc/pipex.h
	@mkdir -p obj
	@cc $(FLAGS) -c $(FILESC)
	@cc $(FLAGS) $(OBJS) -o $(NAME)
	@mv $(OBJS) ./obj

clean :
	@rm -Rf ./obj

fclean : clean
	@rm -Rf $(NAME)

re : fclean all

bonus : $(FILESC) $(BONUSFILESC)
	@sed -i "s/# define BONUS 0/# define BONUS 1/g" ./inc/pipex.h
	@mkdir -p obj
	@cc $(FLAGS) -c $(FILESC) $(BONUSFILESC)
	@cc $(FLAGS) $(OBJS) $(BONUSOBJS) -o $(NAME)
	@mv $(OBJS) $(BONUSOBJS) ./obj