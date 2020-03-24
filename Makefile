# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 18:19:52 by jrignell          #+#    #+#              #
#    Updated: 2020/03/23 17:16:54 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRC_DIR := ./ls_srcs
OBJ_DIR := ./obj

SRC :=	main.c \
		type_mode.c \
		group_owner.c \
		ls_last_modified.c \
		ls_error.c \
		ls_lstadd.c \
		ls_get_flags.c
		

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C printf_srcs/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) printf_srcs/libftprintf.a

clean:
	@/bin/rm -f $(OBJ)
	@make -C printf_srcs/ clean
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@make -C printf_srcs/ fclean
	@make -C libft/ fclean
	
ls: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) printf_srcs/libftprintf.a

re: fclean all

.PHONY: all clean re fclean