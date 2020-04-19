/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:39:40 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/19 17:49:21 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>

void	ls_error(char *path)
{
	char	*str;

	str = ft_joindel(ft_strdup("ft_ls: "), ft_strdup(path));
	perror(str);
	ft_strdel(&str);
}
