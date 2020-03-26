/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 21:41:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/26 21:26:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_print_content(t_list *node, t_ls *flags)
{
	int		(*print)(const char*, ...);

	print = &ft_printf;
	if (flags->l)
	{
		print("%c%s %-4d %3s %.7s %6d % s % s\n", ((t_file*)node->content)->type,
		((t_file*)node->content)->mode, ((t_file*)node->content)->links,
		((t_file*)node->content)->owner, ((t_file*)node->content)->group,
		((t_file*)node->content)->size, ((t_file*)node->content)->last_mod, ((t_file*)node->content)->name);
	}
	else if (flags->not)
		print("%s   ", ((t_file*)node->content)->name);
	// ft_printf("Flags->not %d\n", flags->not);
}
