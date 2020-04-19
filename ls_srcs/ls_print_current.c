/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_current.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 15:57:45 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/19 17:49:03 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ls_print_current(t_ls *flags, t_list **node)
{
	DIR				*dirp;

	if ((dirp = opendir(".")) != NULL)
	{
		ls_read_directories(node, flags, dirp, ".");
	}
	if (closedir(dirp) == -1)
		ls_error(".");
	dirp = NULL;
}
