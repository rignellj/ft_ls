/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstadd_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:25:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 16:20:25 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>

static char	*ret_name(char *s)
{
	char		*ptr;

	ptr = ft_strrchr(s, '/');
	ptr += ptr + 1 != NULL ? 1 : 0;
	return (ptr);
}

static void	ls_read_link(t_file *content, struct stat *buf)
{
	char	*linkname;
	char	*tmp;
	ssize_t	r;

	if (!(linkname = (char *)ft_memalloc(buf->st_size + 1)))
		exit(1);
	tmp = ft_strdup(content->path);
	if (!(r = readlink(tmp, linkname, buf->st_size + 1)))
		ls_error(tmp);
	ft_strdel(&tmp);
	linkname[buf->st_size] = '\0';
	content->symlink = linkname;
}

static void	ls_get_data_l_flag(t_ls *f, t_file *content, struct stat *buf)
{
	f->blocks += buf->st_blocks;
	if (f->links_len < (ft_numlen(content->links = buf->st_nlink)))
		f->links_len = ft_numlen(buf->st_nlink);
	if (f->size_len < (ft_numlen(content->size = buf->st_size)))
		f->size_len = ft_numlen(buf->st_size);
	ls_last_modified(buf, content);
	ls_group_owner(buf, content, f);
	if (content->type == 'l')
		ls_read_link(content, buf);
}

void		ls_lstadd_linkedlist(t_list **node, t_ls *f, char *s, int i)
{
	t_list		*new_node;
	t_file		content;
	
	struct stat	buf;

	if (lstat(s, &buf) == -1)
		ls_error(s);
	ft_bzero(&content, sizeof(t_file));
	f->num_of_nodes++;
	content.path = s;
	content.name = i ? s : ret_name(s);
	if (f->max_name_len < ((int)ft_strlen(i ? s : (ret_name(s)))))
		f->max_name_len = ft_strlen(i ? s : (ret_name(s)));
	ls_type_mode(&buf, &content);
	if (f->l)
		ls_get_data_l_flag(f, &content, &buf);
	if (f->t)
		content.epoc = buf.st_mtime;
	new_node = ft_lstnew(&content, sizeof(t_file));
	ft_lstadd(node, new_node);
}
