/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 20:49:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 20:51:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayzero(void **s, size_t n)
{
	unsigned char	**p;

	p = (unsigned char**)s;
	while (n-- > 0)
		*(p++) = 0;
}
