/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/20 13:05:44 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	launch_ls(int ac, char *av[])
{
	t_list			*node;
	size_t			i;
	t_ls			flags;
	t_list			**head;

	i = 1;
	node = NULL;
	ls_get_flags(&flags, av, &i, ac);
	head = ls_print_not_existing_f(av, &i, &flags, &node);
	if (av[i])
		ls_open_directories(&flags, head, NULL);
	else
		ls_print_current_directory(&flags, &node);
	while (1);
}

int			main(int ac, char *av[])
{
	launch_ls(ac, av);
	return (0);
}
