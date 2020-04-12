/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:56:26 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/12 14:36:36 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long int value, int base, int upper)
{
	char				*s;
	char				*res;
	int					i;
	unsigned long long	temp;

	s = (upper == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	i = 1;
	temp = value;
	while ((temp /= base) > 0)
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	if (!value)
		*res = '0';
	while (value)
	{
		res[--i] = s[value % base];
		value = value / base;
	}
	return (res);
}
