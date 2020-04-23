# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 13:33:40 by jrignell          #+#    #+#              #
#    Updated: 2020/04/23 13:07:32 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
INC_DIR = includes/

SRCS = ft_isalpha.c \
	ft_isupper.c \
	ft_strlen.c \
	ft_atoi.c \
	ft_isdigit.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_isalnum.c \
	ft_islower.c \
	ft_strdup.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_isprint.c \
	ft_isascii.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_bzero.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memalloc.c \
	ft_strnew.c \
	ft_isspace.c \
	ft_strjoin.c \
	ft_memdel.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strtrim.c \
	ft_strsub.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstadd.c \
	ft_lstiter.c \
	get_next_line.c \
	ft_putnbr_ull_fb.c \
	ft_atoi_base.c \
	ft_itoa_base.c \
	ft_itoa_base_u.c \
	ft_lftoa.c \
	ft_implode.c \
	ft_add_char.c  \
	ft_only_space.c \
	ft_lstappend.c \
	ft_mem_arrdel.c \
	ft_joindel.c \
	ft_strfree.c \
	ft_swap.c \
	ft_array_push.c \
	ft_arraynew.c \
	ft_qsort.c \
	ft_arraylen.c \
	ft_print_current_node.c \
	ft_mergesort.c \
	ft_bubblesort.c \
	ft_numlen.c \
	ft_lstget_first.c \
	ft_lstget_last.c \
	ft_lstiterif.c

OBJ  = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRCS) -I $(INC_DIR)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
