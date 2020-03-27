/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:44:53 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 20:37:42 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_push(char const **old, char const *append)
{
	size_t	i;
	char	**new;

	if (!old || !append)
		return (NULL);
	i = 0;
	while (old[i])
		i++;
	if (!(new = (char**)ft_mem_arraymalloc(sizeof(char*) * i + 2)))
		return (NULL);
	i = 0;
	while (old[i])
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	new[i++] = ft_strdup(append);
	ft_mem_arrdel((void**)old);
	new[i] = NULL;
	return (new);
}
