/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_arraymalloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:31:33 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 21:00:09 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_mem_arraymalloc(size_t size)
{
	void	**fresh;

	if (!(fresh = (void**)malloc(sizeof(void*) * size)))
		return (NULL);
	ft_arrayzero(fresh, sizeof(void*) * size);
	return (fresh);
}
