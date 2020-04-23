/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_group_owner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:03:03 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/22 17:54:38 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <pwd.h>
#include <grp.h>

void	ls_group_owner(struct stat *buf, t_file *f, t_ls *flags)
{
	struct passwd	*uid;
	struct group	*gid;

	if (!(uid = getpwuid(buf->st_uid)))
	{
		if (flags->owner_len < ((int)ft_strlen((f->owner = ft_itoa_base_u(buf->st_uid, 10, 0)))))
			flags->owner_len = (int)ft_strlen(f->owner);	
	}
	else
		if (flags->owner_len < ((int)ft_strlen((f->owner = ft_strdup(uid->pw_name)))))
			flags->owner_len = (int)ft_strlen(f->owner);
	if (!(gid = getgrgid(buf->st_gid)))
		f->group = ft_strdup("0");
	else
		if (flags->group_len < ((int)ft_strlen((f->group = ft_strdup(gid->gr_name)))))
		flags->group_len = (int)ft_strlen(gid->gr_name);
}
