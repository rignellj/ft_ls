/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:42:54 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/06 14:57:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_file_add(t_list **node, char *file_name, struct stat *buf, char *path)
{
	t_file			*current;
	t_list			*new;
	static size_t	num_of_elem = 0;

	if (!(current = ft_memalloc(sizeof(t_file))))
		ls_error();
	current->path = path;
	current->name = file_name;
	current->links = buf->st_nlink;
	current->size = buf->st_size;
	current->logical_len += num_of_elem;
	ls_type_mode(buf, current);
	ls_group_owner(buf, current);
	ls_last_modified(buf, current);
	// while (1);
	new = ft_lstnew(current, sizeof(t_file));
	if (current->name[0] == '.' || (current->name[0] <= 'Z' && current->name[0] >= 'A'))
		ft_lstadd(node, new);
	else
		ft_lstappend(node, new);
}

static void	ls_dir_add(t_list **node, DIR *dirp, char *av)
{
	struct dirent	*file_dir_name;
	struct stat		file_buf;
	char			*path;
	char			*file_name;
	
//	join = ft_strnew(0);
//	ls_file_add(node, av, buf); // add dir to linked list
	while ((file_dir_name = readdir(dirp)))
	{
		file_name = ft_add_char(file_dir_name->d_name, '/');
		path = ft_joindel(ft_strdup(av), file_name);
		lstat(path, &file_buf);
//		ft_printf("path %s\n", path);
		// ft_printf("file name: %s\nfile mode: %s\n", file_dir_name->d_name, ft_itoa_base(file_buf.st_mode, 8, 0));
		ls_file_add(node, file_dir_name->d_name, &file_buf, path);
		ft_strdel(&path);
	}
}

void		ls_lstadd(t_list **node, char *av)
{
	// struct stat		buf;
	DIR				*dirp;

	if ((dirp = opendir(av)) != NULL)// && lstat(av, &buf) == 0) //open directory, buf stores info about directory
	{
		ls_dir_add(node, dirp, av);
		if (closedir(dirp))
			ls_error();
	}
	// else if ((dirp = opendir(av)) == NULL && lstat(av, &buf) == 0) //file
	// {
	// 	ls_file_add(node, av, &buf, NULL);
	// }
	// else if ((dirp = opendir(av)) == NULL && lstat(av, &buf) == -1)
	// 	add_file_not_exist(node, av);
	// else
	// 	ls_error();
}
