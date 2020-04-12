/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 16:47:41 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/11 17:19:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_lstdel(t_list **node, t_ls *flags)
{
	t_list	*current;
	t_list	*tmp;

	if (!*node)
		return ;
	current = *node;
	while (current)
	{
		// ft_printf("here\n");
		// ls_print_content(current, flags);
		if (!current->next)
			break ;
		tmp = current->next;
		if (flags->l)
		{
			ft_memdel((void**)&((t_file*)current->content)->last_mod);
			ft_memdel((void**)&((t_file*)current->content)->mode);
		}
		ft_memdel((void**)&((t_file*)current->content)->path);
		// ft_memdel((void**)&((t_file*)current->content)->name);
		ft_memdel((void**)&(current->content));
		ft_memdel((void**)&current);
		current = tmp;
	}
}
