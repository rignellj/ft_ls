/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_del_current.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 18:58:52 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/08 18:44:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_del_current(t_list **node, t_list *del, t_ls *f)
{
	if (*node == NULL || del == NULL)
		return ;
	if (*node == del)
		*node = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	if (f->l)
	{
		ft_memdel((void**)&((t_file*)del->content)->last_mod);
		ft_memdel((void**)&((t_file*)del->content)->mode);
	}
	ft_memdel((void**)&((t_file*)del->content)->path);
	ft_memdel((void**)&(del->content));
	ft_memdel((void**)&del);
}
