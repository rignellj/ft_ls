/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:50:04 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/13 16:03:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_numlen(long long num)
{
	if (num < 0)
		return (ft_numlen(FT_ABS(num)) + 1);
	if (num >= 0 && num <= 9)
		return (1);
	else
		return (ft_numlen(num / 10) + 1);
}
