/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 12:37:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/04 17:29:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	q_partition(char **str, int first, int last,
			int (*cmp)(void*, void*))
{
	char	*pivot;
	int		start;
	int		end;

	pivot = str[first];
	start = first;
	end = last;
	while (start < end)
	{
		while (start < last && cmp(str[start], pivot) <= 0)
			start++;
		while (end >= first && cmp(str[end], pivot) > 0)
			end--;
		if (start < end)
			ft_swap((void**)&str[start], (void**)&str[end]);
	}
	ft_swap((void**)&str[first], (void**)&str[end]);
	return (end);
}

void		ft_qsort(char **str, int first, int last, int (*cmp)(void*, void*))
{
	int		i;

	if (first < last)
	{
		i = q_partition(str, first, last, cmp);
		ft_qsort(str, first, i - 1, cmp);
		ft_qsort(str, i + 1, last, cmp);
	}
}
