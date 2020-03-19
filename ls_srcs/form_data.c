/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:10:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/18 19:55:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ls_form_data(struct stat *buf, char **av)
{
	t_f				f;
	
	ft_bzero(&f, sizeof(f));
	f.name = av[1];
	ls_type_mode(buf, &f);
	f.links = buf->st_nlink;
	ls_group_owner(buf, &f);
	f.size = buf->st_size;
	ls_last_modified(buf, &f);
	ft_printf("Name: %s\nType: %c\nModes: %s\nLinks: %d\nOwner: %s\nGroup: %s\nSize: %d\nLast modification date: %s", f.name,
		f.type, f.mode, f.links, f.owner, f.group, f.size, f.last_mod);
}