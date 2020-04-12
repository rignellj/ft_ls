/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstadd_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:25:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/11 17:14:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*ret_name(char *s)
{
	char		*ptr;

	ptr =  ft_strrchr(s, '/');
	ptr += ptr + 1 != NULL ? 1 : 0;
	return (ptr);
}

void		ls_lstadd_linkedlist(t_list **node, t_ls *f, char *s, int i)
{
	t_list		*new_node;
	struct stat	buf;

	if (!(new_node = (t_list*)ft_memalloc(sizeof(t_list))))
		ls_error();
	if (!(new_node->content = (t_file*)ft_memalloc(sizeof(t_file))))
		ls_error();
	if (lstat(s, &buf) == -1)
		ls_error();
	((t_file*)new_node->content)->path = ft_strdup(s);
	((t_file*)new_node->content)->name = i ? s : ret_name(s);
	ls_type_mode(&buf, new_node->content);
	if (f->l)
	{
		((t_file*)new_node->content)->links = buf.st_nlink;
		((t_file*)new_node->content)->size = buf.st_size;
		ls_group_owner(&buf, new_node->content);
		ls_last_modified(&buf, new_node->content);
	}
	if (f->t)
		((t_file*)new_node->content)->epoc = buf.st_mtime;
	new_node = ft_lstnew(((t_file*)new_node->content), sizeof(t_file));
	ft_lstadd(node, new_node);
}
