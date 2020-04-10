# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 18:19:52 by jrignell          #+#    #+#              #
#    Updated: 2020/04/10 18:42:26 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRC_DIR := ./ls_srcs
OBJ_DIR := ./obj

SRC :=	main.c \
		ls_type_mode.c \
		ls_group_owner.c \
		ls_last_modified.c \
		ls_error.c \
		ls_lstadd.c \
		ls_get_flags.c \
		ls_print_content.c \
		ft_mergesort.c \
		ls_print_not_existing_f.c \
		ls_open_directories.c \
		ls_compare.c \
		print_not_existing_files.c \
		ls_bubblesort.c \
		ls_del_current.c \
		ls_lstadd_linkedlist.c \
		print_current.c \
		ls_print_current.c \
		ls_find.c
		

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