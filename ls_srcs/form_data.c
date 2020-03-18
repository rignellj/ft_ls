/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:10:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/18 16:16:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ls_form_data(struct stat *buf, char **av)
{
	t_f		f;
	
	ft_bzero(&f, sizeof(f));
	f.name = av[1];
	ls_type_mode(buf, &f);
//	ls_links(buf, &f);
	f.links = buf->st_nlink;
	ft_printf("Name: %s\nType: %c\nModes: %s\nLinks: %d\n", f.name, f.type, f.mode, f.links);
}