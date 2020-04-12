/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_check_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:33:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/12 14:23:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	define_asterisk(t_format *f, va_list ap)
{
	if (*(f->star - 1) != '.')
	{
		f->width = va_arg(ap, unsigned);
	}
	else
		f->prec = va_arg(ap, unsigned);
}

int		ft_check_if_width(t_format *f)
{
	char			*ptr;
	int				ret;
	unsigned int	i;

	ret = 0;
	if ((ptr = ft_strchr(f->s_str, '$')) != NULL)
	{
		ret = ft_atoi(++ptr);
		ptr = NULL;
		return (ret);
	}
	else
		i = 0;
	ptr = NULL;
	while (f->s_str[i] && f->s_str[i] != '.')
	{
		if (f->s_str[i] != '0' && ft_isdigit(f->s_str[i]))
			return (ft_atoi(&f->s_str[i]));
		i++;
	}
	return (0);
}

int		iszero(t_format *f)
{
	int		i;

	i = 0;
	while (f->s_str[i])
	{
		if (f->s_str[i] == '.' || (f->s_str[i] >= '1' && f->s_str[i] <= '9'))
			return (0);
		else if (f->s_str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
