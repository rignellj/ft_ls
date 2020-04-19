/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:55:03 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/19 12:33:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list	*ls_find_first(t_list *current)
{
	t_list	*first;

	first = current;
	while (first)
	{
		if (!first->prev)
			break ;
		first = first->prev;
	}
	return (first);
}

t_list	*ls_find_last(t_list *current)
{
	t_list	*last;

	last = current;
	while (last)
	{
		if (!last->next)
			break ;
		last = last->next;
	}
	return (last);
}
