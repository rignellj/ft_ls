/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/10 17:44:44 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
/*
	void		print_exists(void *n)
	{
		ft_printf("Exists: %d\n", *(int*)n);
	}
*/
/*
	void		print_flags(t_ls *flags)
	{
		ft_printf("a: %d\n", flags->a);
		ft_printf("l: %d\n", flags->l);
		ft_printf("r: %d\n", flags->r);
		ft_printf("R: %d\n", flags->rec);
		ft_printf("t: %d\n", flags->t);
	}
*/

static void	get_file_mode(int ac, char *av[])
{
	t_list			*node;
	size_t			i;
	t_ls			flags;

	i = 1;
	node = NULL;
	ac = 0;
	ls_get_flags(&flags, av, &i);
	av[i] ? ls_open_directories(&flags, ls_print_not_existing_f(av, &i, &flags, &node), NULL) : ls_print_current(&flags);
}

int			main(int ac, char *av[])
{
	get_file_mode(ac, av);
	return (0);
}
