/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/14 17:00:49 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
// #include <stdio.h>

static void	get_file_mode(int ac, char *av[])
{
	t_list			*node;
	size_t			i;
	t_ls			flags;

	i = 1;
	node = NULL;
	ls_get_flags(&flags, av, &i, ac);
	av[i] ? ls_open_directories(&flags, ls_print_not_existing_f(av, &i, &flags,
	&node), NULL, 0) : ls_print_current(&flags, &node);
	// perror("ft_ls: ");
}

int			main(int ac, char *av[])
{
	get_file_mode(ac, av);
	return (0);
}
