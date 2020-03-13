# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 18:19:52 by jrignell          #+#    #+#              #
#    Updated: 2020/03/13 19:57:30 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRC_DIR := ./ls_srcs
OBJ_DIR := ./obj

SRC := test.c

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C printf_srcs/
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) printf_srcs/libftprintf.a

clean:
	@/bin/rm -f $(OBJ)
	@make -C printf_srcs/ clean
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@make -C printf_srcs/ fclean
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean re fclean