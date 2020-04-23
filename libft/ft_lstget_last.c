/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:41:38 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/21 11:44:36 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_last(t_list *current)
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
