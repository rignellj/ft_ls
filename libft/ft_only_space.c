/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:42:19 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/15 18:57:07 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_only_space(char *s)
{
	size_t	i;
	size_t	j;
	char	*trim;
	char	*new;

	if (!s)
		return (NULL);
	trim = ft_strtrim(s);
	if (!(new = ft_strnew(ft_strlen(trim))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (!ft_isspace(trim[i]))
			new[j++] = trim[i++];
		new[j++] = ' ';
		while (ft_isspace(trim[i]) && trim[i])
			i++;
	}
	ft_strdel(&trim);
	return (new);
}
