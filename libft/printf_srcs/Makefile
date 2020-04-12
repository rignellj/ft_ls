# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:53:22 by jrignell          #+#    #+#              #
#    Updated: 2020/04/11 13:47:41 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
INC_DIR = includes/

SRCS = 	ft_printf.c \
		ft_parse_diouxf.c \
		ft_parse_hh_h_ll_l.c \
		check_bef_format.c \
		check_bef_format_u.c \
		ft_parse_width.c \
		ft_parse_f.c \
		ft_precision.c \
		ft_parse_csp_percent.c \
		ft_parse_flags.c \
		ft_helpers.c \
		ft_helpers_check_functions.c \
		ft_parse_brk.c \
		print_array.c

OBJ =	$(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME):
	@make -C ../
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(INC_DIR)
	@cp ../libft.a ./libftprintf.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean:
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)

re: fclean all
	
.PHONY: all clean fclean re
