/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_not_existing_f.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:30:49 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 16:42:11 by jrignell         ###   ########.fr       */
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
	t_list	*cur;

	cur = *node;
	if (f->l && !i)
		f->a || !ft_lstiterif(cur, &ls_iter_until) ?
		ft_printf("total %lld\n", f->blocks) : 0;
	while (cur)
	{
		if (i && cur->content && ((t_file*)cur->content)->type != 'd')
		{
			ls_print_content(cur, f);
			ls_del_current(node, cur, f);
		}
		else if (!i && cur->content && !((t_file*)cur->content)->printed)
		{
			ls_print_content(cur, f);
		}
		cur = f->r ? cur->prev : cur->next;
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
	*ret_dirs = ft_mergesort(*ret_dirs, flags->fptr[0]);
	if (flags->r)
		*ret_dirs = ft_lstget_last(*ret_dirs);
	ls_print_files_del(ret_dirs, flags, 1);
	return (ret_dirs);
}
