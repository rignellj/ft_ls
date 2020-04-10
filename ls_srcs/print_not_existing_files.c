/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_not_existing_files.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:30:32 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/06 13:31:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ls_print_not_existing_files(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_printf("ft_ls: %s: No such file or directory\n", array[i]);
		i++;
	}
	ft_mem_arrdel((void**)array);
}
