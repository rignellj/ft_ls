/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:51:31 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 20:57:25 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraynew(size_t size)
{
	char	**new;
	size_t	i;

	if (!(new = (char**)ft_mem_arraymalloc(sizeof(char*) * size + 1)))
		return (NULL);
	i = 0;
	
	while (i < size)
		new[i++] = NULL;
	return (new);
}
