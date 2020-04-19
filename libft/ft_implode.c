/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:32:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/17 16:04:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_implode(char **s)
{
	size_t	i;
	char	*tmp3;
	char	*tmp;
	char	*tmp2;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	tmp = ft_strdup("\0");
	while (s[i])
	{
		tmp2 = ft_strdup(s[i]);
		tmp3 = ft_add_char(tmp2, ' ');
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(tmp, tmp3);
		ft_strdel(&tmp);
		ft_strdel(&tmp3);
		tmp = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		i++;
	}
	ret = ft_strtrim(tmp);
	ft_strdel(&tmp);
	return (ret);
}
