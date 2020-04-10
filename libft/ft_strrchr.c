/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:29:51 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/05 14:39:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_o;

	last_o = (0);
	while (*s)
	{
		if (*s == c)
			last_o = (char*)s;
		++s;
	}
	if (last_o)
		return (last_o);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
