/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_not_existing_f.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:30:49 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/10 17:43:16 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ls_lstat(char *av)
{
	struct stat	buf;

	if (lstat(av, &buf) == 0)
		return (1);
	else
		return (0);
}

void	ls_print_files_del(t_list **node, t_ls *f, int i)
{
	t_list	*current;

	current = *node;
	while (current)
	{
		if (i && current->content && ((t_file*)current->content)->type != 'd')
		{
			ft_printf("%s ", ((t_file*)current->content)->name);
			ls_del_current(node, current, f);
		}
		else if (!i && current->content)
		{
			ft_printf("%s ", ((t_file*)current->content)->name);
			ls_del_current(node, current, f);
		}
		current = current->next;
	}
	ft_putchar('\n');
}

t_list		**ls_print_not_existing_f(char *av[], size_t *i, t_ls *flags, t_list **ret_dirs)
{
	char	**not_exist;
	size_t	j;

	not_exist = ft_arraynew(0);
	j = *i;
	while (av[j])
	{
		if (!ls_lstat(av[j]))
			not_exist = ft_array_push(not_exist, av[j]);
		else
			ls_lstadd_linkedlist(ret_dirs, flags, av[j], 1);
		j++;
	}
	ls_bubblesort(not_exist);
	ls_print_not_existing_files(not_exist);
	ft_mergesort(*ret_dirs);
	*ret_dirs = ls_find_first(*ret_dirs);
	ls_print_files_del(ret_dirs, flags, 1);
	return (ret_dirs);
}
