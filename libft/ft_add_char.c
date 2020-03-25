/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:07:09 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/25 17:30:52 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_char(char *s, int c)
{
	char	*tmp;
	char	*ret;
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	tmp = ft_strdup(s);
	ret = ft_joindel(str, tmp);
	return (ret);
}
