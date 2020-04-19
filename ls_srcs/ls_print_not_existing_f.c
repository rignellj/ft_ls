/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_not_existing_f.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:30:49 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/19 17:46:26 by jrignell         ###   ########.fr       */
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

static void	ls_print_not_existing_files(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_printf("ft_ls: %s: No such file or directory\n", array[i]);
		i++;
	}
	ft_mem_arrdel((void**)array);
}

void		ls_print_files_del(t_list **node, t_ls *f, int i)
{
	t_list	*current;

	current = *node;
	while (current)
	{
		if (i && current->content && ((t_file*)current->content)->type != 'd')
		{
			ls_print_content(current, f, 1, 1);
			ls_del_current(node, current, f);
		}
		else if (!i && current->content)
		{
			ls_print_content(current, f, current->next ? 0 : 1, 0);
		}
		
		current = current->next;
	}
}

t_list		**ls_print_not_existing_f(char *av[], size_t *i,
			t_ls *flags, t_list **ret_dirs)
{
	char	**not_exist;
	size_t	j;

	if (!(not_exist = ft_arraynew(0)))
		exit(1);
	j = *i;
	while (av[j])
	{
		if (!ls_lstat(av[j]))
			not_exist = ft_array_push(not_exist, av[j]);
		else
			ls_lstadd_linkedlist(ret_dirs, flags, ft_strdup(av[j]), 1);//protect
		j++;
	}
	ft_bubblesort(not_exist);
	ls_print_not_existing_files(not_exist);
	ft_mergesort(*ret_dirs, flags->fptr[0]);
	*ret_dirs = ls_find_first(*ret_dirs);
	ls_print_files_del(ret_dirs, flags, 1);
	return (ret_dirs);
}
