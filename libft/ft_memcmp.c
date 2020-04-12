/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:05:02 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/12 14:39:39 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char*)s1;
	j = (unsigned char*)s2;
	if (!(*i || *j))
		return (0);
	while (n-- > 0 && *i++ == *j++)
		;
	return ((int)(*--i - *--j));
}
