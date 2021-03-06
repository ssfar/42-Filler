# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:15:55 by ssfar             #+#    #+#              #
#    Updated: 2020/07/03 23:35:46 by ssfar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = ssfar.filler
LFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I ./libft/includes


INC_DIR = includes
SRC_DIR = sources
OBJ_DIR = objects

SRC_NAME =	cross.c \
			filler.c \
			global_shape.c \
			heatmap.c \
			loop.c \
			x.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))

EOC			= \033[0;0m
RED			= \033[0;31m
GREEN		= \033[0;32m

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@make -C ./visualiseur
	@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $@
	@chmod 755 $(NAME)
	@printf "$(GREEN)$(NAME) Makefile : $(OBJ_DIR) and $(NAME) created\n$(EOC)"
$(LFT) : FORCE
	@make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft fclean
	@make -C ./visualiseur fclean
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)$(NAME) Makefile : $(OBJ_DIR) deleted\n$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) Makefile : $(NAME) deleted\n$(EOC)"

re: fclean all
FORCE:
