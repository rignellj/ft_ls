/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_diouxf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:32:49 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/03 17:04:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		diouxf(t_format *f, va_list ap)
{
	f->star = ft_strchr(f->s_str, '*');
	if (f->star)
		define_asterisk(f, ap);
	if (f->format == 'd' || f->format == 'i')
		return (check_bef_format(f, va_arg(ap, long long)));
	else if (f->format == 'o' || f->format == 'u'
			|| f->format == 'x' || f->format == 'X')
		return (check_bef_format_u(f, va_arg(ap, unsigned long long)));
	else if (f->format == 'f')
		return (ft_parse_f(f, ap));
	else if (f->format == 'c' || f->format == 's'
			|| f->format == 'p' || f->format == '%')
		return (ft_parse_csp_percent(f, ap));
	else if (f->format == 'b')
		return (printf_bonus(f, va_arg(ap, unsigned long long)));
	else if (f->format == 'a')
		return (print_array(f, va_arg(ap, char**)));
	return (0);
}
