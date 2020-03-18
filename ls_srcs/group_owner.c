/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_owner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:03:03 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/18 19:21:20 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ls_group_owner(struct stat *buf, t_f *f)
{
	struct passwd	*uid;
	struct group	*gid;
	
	uid = getpwuid(buf->st_uid);
	f->owner = uid->pw_name;
	gid = getgrgid(buf->st_gid);
	f->group = gid->gr_name;
}