/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 21:41:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/18 14:01:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	last_file(t_list *current)
{
	t_list	*compare;

	if (!current)
		return (1);
	compare = current;
	while (current)
	{
		if (((t_file*)current->content)->type == '-' && compare != current)
			return (0);
		current = current->next;
	}
	return (1);
}

void		ls_print_content(t_list *current, t_ls *flags, int i, int y)
{
	int		(*print)(const char*, ...);

	print = &ft_printf;
	if (flags->l)
	{
		print("%c%s  %*d %-*s  %-*s  %*d %s %s\n",
		((t_file*)(current)->content)->type,
		((t_file*)(current)->content)->mode,
		flags->links_len, ((t_file*)(current)->content)->links,
		flags->owner_len, ((t_file*)(current)->content)->owner,
		flags->group_len, ((t_file*)(current)->content)->group,
		flags->size_len, ((t_file*)(current)->content)->size,
		((t_file*)(current)->content)->last_mod,
		((t_file*)(current)->content)->name);
	}
	else
	{
		print("%s", ((t_file*)(current)->content)->name);
		last_file(current) && i ? ft_putchar('\n') : ft_putstr("    ");
		y ? ft_putchar('\n') : 0;
	}
}
