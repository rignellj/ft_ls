/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 21:41:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/14 13:06:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_print_content(t_list *current, t_ls *flags)
{
	int		(*print)(const char*, ...);

	print = &ft_printf;
	if (flags->l)
	{
		print("%c%s %*d %3s %.7s %6d % s % s\n", ((t_file*)(current)->content)->type,
		((t_file*)(current)->content)->mode, flags->links_len, ((t_file*)(current)->content)->links,
		((t_file*)(current)->content)->owner, ((t_file*)(current)->content)->group,
		((t_file*)(current)->content)->size, ((t_file*)(current)->content)->last_mod, ((t_file*)(current)->content)->name);
	}
	else
		print("%s   ", ((t_file*)(current)->content)->name);
	if (!current->next)
		ft_putchar('\n');
}
