/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:09:24 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/12 14:39:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!n)
		return (0);
	while (n-- > 0)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if ((unsigned char)c == *(unsigned char*)src)
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
