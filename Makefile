# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 13:15:41 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/26 12:00:36 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

#srcs
PATHFC = ./srcs/mandatory/
PATHCE = $(PATHFC)check_errors/
PATHIGD = $(PATHFC)init_get_data/
PATHPE = $(PATHFC)parsing_errors/
PATHIGLK = $(PATHFC)init_get_lk/
PATHRC = $(PATHFC)run_cmds/
PATHPIE = $(PATHFC)pipex_errors/
PATHLKE = $(PATHFC)lk_error/
PATHU = $(PATHFC)utils/
PATHIP = $(PATHFC)init_pipes_data/
FILESC = ./srcs/pipex.c $(PATHIGD)init_and_get_splitted_path.c \
$(PATHIGD)init_and_get_command.c $(PATHIGD)get_path.c $(PATHPE)print_errors.c \
$(PATHPE)print_malloc_errors.c $(PATHIGLK)init_get_lk.c $(PATHIGLK)get_cmd.c \
$(PATHRC)run_last_cmd.c $(PATHRC)run_first_cmd.c $(PATHPIE)pipex_errors.c \
$(PATHLKE)lk_errors.c $(PATHU)destroy_data.c $(PATHU)utils.c \
$(PATHCE)check_all_errors.c $(PATHIP)prepare_pipes_data.c \
$(PATHPIE)here_doc_check.c $(PATHU)common_fct.c
OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

#bonus
PATHBONUS = ./srcs/bonus/
BONUSFILESC = $(PATHBONUS)run_mid_cmds_bonus.c \
$(PATHBONUS)init_here_doc_bonus.c $(PATHBONUS)get_next_line_bonus.c \
$(PATHBONUS)here_doc_pipe.c
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