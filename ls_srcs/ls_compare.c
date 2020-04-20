/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:53:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/20 12:52:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		compare_low_high_int(void *i1, void *i2)
{
	size_t	i;
	t_file	*ptr1;
	t_file	*ptr2;

	i = 0;
	ptr1 = (t_file*)i1;
	ptr2 = (t_file*)i2;
	if (ptr1->epoc == ptr2->epoc)
		return (compare_high_low(i1, i2));
	if (ptr1->epoc > ptr2->epoc)
		return (-1);
	if (ptr1->epoc < ptr2->epoc)
		return (1);
	return (1);
}

int		compare_low_high(void *s1, void *s2)
{
	size_t	i;
	t_file	*ptr1;
	t_file	*ptr2;

	i = 0;
	ptr1 = (t_file*)s1;
	ptr2 = (t_file*)s2;
	while (ptr1->name[i] == ptr2->name[i] && ptr1->name && ptr2->name)
		i++;
	return ((unsigned char)ptr1->name[i] - (unsigned char)ptr2->name[i]);
}

int		compare_high_low(void *s1, void *s2)
{
	size_t	i;
	t_file	*ptr1;
	t_file	*ptr2;

	i = 0;
	ptr1 = (t_file*)s1;
	ptr2 = (t_file*)s2;
	while (ptr1->name[i] == ptr2->name[i] && ptr1->name && ptr2->name)
		i++;
	return ((unsigned char)ptr2->name[i] - (unsigned char)ptr1->name[i]);
}
