/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:51:31 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/15 19:51:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_arraynew(size_t size)
{
	char	**new;
	size_t	i;

	if (!(new = (char **)malloc(sizeof(*new) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = NULL;
	new[i] = NULL;
	return (new);
}
