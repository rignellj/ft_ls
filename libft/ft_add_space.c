/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:07:09 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/19 20:07:34 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_space(char *s)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(s);
	ret = ft_strjoin(" ", tmp);
	ft_strdel(&tmp);
	ft_strdel(&s);
	return (ret);
}
