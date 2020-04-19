# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 18:19:52 by jrignell          #+#    #+#              #
#    Updated: 2020/04/19 20:51:26 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc

INC_DIR := ./includes
SRC_DIR := ./ls_srcs
OBJ_DIR := ./obj

SRC :=	main.c \
		ls_type_mode.c \
		ls_group_owner.c \
		ls_last_modified.c \
		ls_error.c \
		ls_get_flags.c \
		ls_print_content.c \
		ls_print_not_existing_f.c \
		ls_open_and_read_directories.c \
		ls_compare.c \
		ls_del_current.c \
		ls_lstadd_linkedlist.c \
		ls_print_current_directory.c \
		ls_find.c \
		ls_lstdel.c
		

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/printf_srcs/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/printf_srcs/libftprintf.a

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/printf_srcs/ clean
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@make -C libft/printf_srcs/ fclean
	@make -C libft/ fclean
	
ls: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/printf_srcs/libftprintf.a

re: fclean all

.PHONY: all clean re fclean