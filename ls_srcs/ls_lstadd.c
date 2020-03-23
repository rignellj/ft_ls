/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:42:54 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/23 15:48:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	add_file_not_exist(t_list **node, char *file_name)
{
	t_file	*current;
	t_list	*new;

	if (!(current = ft_memalloc(sizeof(t_file))))
		ls_error();
	current->name = file_name;
	current->exist = 0;
	new = ft_lstnew(current, sizeof(t_file));
	ft_lstadd(node, new);
}

static void	ls_file_add(t_list **node, char *file_name, struct stat *buf)
{
	t_file	*current;
	t_list	*new;

	if (!(current = ft_memalloc(sizeof(t_file))))
		ls_error();
	current->name = file_name;
	current->links = buf->st_nlink;
	current->size = buf->st_size;
	ls_type_mode(buf, current);
	ls_group_owner(buf, current);
	ls_last_modified(buf, current);
	current->exist = 1;
	new = ft_lstnew(current, sizeof(t_file));
	if (current->name[0] <= 'Z')
		ft_lstadd(node, new);
	else
		ft_lstappend(node, new);
}

static void	ls_dir_add(t_list **node, DIR *dirp, struct stat *buf)
{
	struct dirent	*name;
	
	while ((name = readdir(dirp)))
	{
		ls_file_add(node, name->d_name, buf);
	}
}

void		ls_lstadd(t_list **node, char *av)
{
	struct stat		buf;
	DIR				*dirp;

	if ((dirp = opendir(av)) != NULL && lstat(av, &buf) == 0)
	{
		ls_dir_add(node, dirp, &buf);
		if (closedir(dirp))
			ls_error();
	}
	else if ((dirp = opendir(av)) == NULL && lstat(av, &buf) == 0)
	{
		ls_file_add(node, av, &buf);
	}
	else if ((dirp = opendir(av)) == NULL && lstat(av, &buf) == -1)
		add_file_not_exist(node, av);
	else
		ls_error();
}
