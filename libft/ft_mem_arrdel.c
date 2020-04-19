/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_arrdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 17:05:00 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/17 17:34:49 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_mem_arrdel(void **tab)
{
	size_t	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			ft_memdel(&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
