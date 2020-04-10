/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:33:08 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/06 13:33:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ls_bubblesort(char **array)
{
	int		flag;
	int		i;

	if (!array)
		return ;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (array[i] && array[i + 1])
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				ft_swap((void**)&array[i], (void**)&array[i + 1]);
				flag = 1;
			}
			i++;
		}
	}
}