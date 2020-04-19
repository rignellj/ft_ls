/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstadd_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:25:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/19 17:57:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*ret_name(char *s)
{
	char		*ptr;

	ptr = ft_strrchr(s, '/');
	ptr += ptr + 1 != NULL ? 1 : 0;
	return (ptr);
}

void		ls_lstadd_linkedlist(t_list **node, t_ls *f, char *s, int i)
{
	t_list		*new_node;
	t_file		content;
	struct stat	buf;

	if (lstat(s, &buf) == -1)
		ls_error(s);
	content.path = s;
	content.name = i ? s : ret_name(s);
	ls_type_mode(&buf, &content);
	if (f->l)
	{
		f->blocks += buf.st_blocks;
		if (f->links_len < (ft_numlen(content.links = buf.st_nlink)))
			f->links_len = ft_numlen(buf.st_nlink);
		if (f->size_len < (ft_numlen(content.size = buf.st_size)))
			f->size_len = ft_numlen(buf.st_size);
		ls_group_owner(&buf, &content, f);
		ls_last_modified(&buf, &content);
		
	}
	if (f->t)
		content.epoc = buf.st_mtime;
	new_node = ft_lstnew(&content, sizeof(t_file));
	ft_lstadd(node, new_node);
}
