/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 21:41:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 17:30:18 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/ioctl.h>

static void	ls_print_l(t_list *current, t_ls *flags)
{
	ft_printf("%c%s  %*d %-*s  %-*s  %*d %12s %s",
		((t_file*)(current)->content)->type,
		((t_file*)(current)->content)->mode,
		flags->links_len, ((t_file*)(current)->content)->links,
		flags->owner_len, ((t_file*)(current)->content)->owner,
		flags->group_len, ((t_file*)(current)->content)->group,
		flags->size_len, ((t_file*)(current)->content)->size,
		((t_file*)(current)->content)->last_mod,
		((t_file*)(current)->content)->name);
	if (((t_file*)(current)->content)->type == 'l')
	{
		ft_printf(" -> %s", ((t_file*)(current)->content)->symlink);
		ft_strdel(&((t_file*)(current)->content)->symlink);
	}
	ft_putchar('\n');
}

static void	ls_print_aligned(t_list *cur, t_ls *flags, struct winsize *w)
{
	t_list	*tmp;
	int		skip;
	int		tmp_skip;
	int		columns;
	int		over;

	tmp = cur;
	if ((columns = w->ws_col / (flags->max_name_len + 1)) <= 0)
		columns = 1;
	over = flags->num_of_nodes % columns;
	tmp_skip = flags->num_of_nodes / columns + (over && columns >= 2 ? 1 : 0);
	ft_printf("%-*s", (flags->max_name_len + 1), ((t_file*)cur->content)->name);
	((t_file*)cur->content)->printed = 1;
	while (tmp && --columns)
	{
		skip = tmp_skip;
		while (tmp && skip--)
			tmp = flags->r ? tmp->prev : tmp->next;
		if (!tmp)
			break ;
		ft_printf("%-*s", flags->max_name_len + 1,
		((t_file*)(tmp)->content)->name);
		((t_file*)tmp->content)->printed = 1;
	}
	ft_putchar('\n');
}

void		ls_print_content(t_list *current, t_ls *flags)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (flags->l)
		ls_print_l(current, flags);
	else if (flags->num_of_nodes >= (w.ws_col / (flags->max_name_len + 1)))
		ls_print_aligned(current, flags, &w);
	else
	{
		if (flags->r)
			current->prev ? ft_printf("%-*s", flags->max_name_len + 1,
			((t_file*)(current)->content)->name) : ft_printf("%s\n",
			((t_file*)(current)->content)->name);
		else
			current->next ? ft_printf("%-*s", flags->max_name_len + 1,
			((t_file*)(current)->content)->name) : ft_printf("%s\n",
			((t_file*)(current)->content)->name);
	}
}
