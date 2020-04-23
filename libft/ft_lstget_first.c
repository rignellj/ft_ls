/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:41:01 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/21 11:44:33 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_first(t_list *current)
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
