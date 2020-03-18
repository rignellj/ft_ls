/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_last_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:26:57 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/18 19:54:39 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ls_last_modified(struct stat *buf, t_f *f)
{
	long			epoc_time;

	epoc_time = buf->st_mtime;
	f->last_mod = ctime(&epoc_time);
	//ft_printf("%s\n", f->last_mod);
}