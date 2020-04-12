/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:53:01 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/12 14:42:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	size_t	i;

	if (!s || !(fresh = ft_memalloc(ft_strlen((const char*)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] && f)
	{
		fresh[i] = f(i, s[i]);
		++i;
	}
	return (fresh);
}
