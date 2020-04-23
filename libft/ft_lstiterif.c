/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiterif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:00:44 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 13:04:01 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstiterif(t_list *lst, int (*f)(t_list *elem))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!f(ptr))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
