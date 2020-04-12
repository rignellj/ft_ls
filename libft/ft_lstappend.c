/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:22:27 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/12 14:38:21 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!alst)
		return ;
	new->next = NULL;
	if ((*alst) == NULL)
	{
		new->prev = NULL;
		(*alst) = new;
	}
	else
	{
		current = (*alst);
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}
