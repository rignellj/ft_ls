/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_group_owner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:03:03 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/14 13:12:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ls_group_owner(struct stat *buf, t_file *f, t_ls *flags)
{
	struct passwd	*uid;
	struct group	*gid;
	
	uid = getpwuid(buf->st_uid);
	if (flags->owner_len < ((int)ft_strlen((f->owner = uid->pw_name))))
		flags->owner_len = (int)ft_strlen(uid->pw_name);
	// f->owner = uid->pw_name;
	gid = getgrgid(buf->st_gid);
	if (flags->group_len < ((int)ft_strlen((f->group = gid->gr_name))))
		flags->group_len = (int)ft_strlen(gid->gr_name);
	// f->group = gid->gr_name;
}