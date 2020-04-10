/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:53:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/04 17:24:05 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		compare_low_high(void *s1, void *s2)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		++i;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int		compare_high_low(void *s1, void *s2)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		++i;
	return ((unsigned char)str2[i] - (unsigned char)str1[i]);
}
