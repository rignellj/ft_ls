/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_open_and_read_directories.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:16:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 17:24:49 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	dont_open(char *str, char *dir)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = ft_strrchr(str, '/');
	if (ptr1 == NULL)
	{
		dir ? ft_putstr("\n") : 0;
		return (1);
	}
	ptr1++;
	ptr2 = ptr1;
	ptr2++;
	if (*ptr1 == '.' && *ptr2 == '\0')
		return (0);
	else if (*ptr1 == '.' && *ptr2 == '.' && ft_strlen(ptr1) == 2)
		return (0);
	dir ? ft_putstr("\n") : 0;
	return (1);
}

static char	*join_path(char *path, char *name, t_ls *flags)
{
	char	*new_path;

	if (flags->a == 0 && *name == '.')
		return (NULL);
	new_path = ft_joindel(ft_joindel(ft_strdup(path), ft_strdup("/")),
	ft_strdup(name));
	return (new_path);
}

static void	ls_flags_init(t_ls *flags)
{
	flags->blocks = 0;
	flags->num_of_nodes = 0;
	flags->group_len = 1;
	flags->owner_len = 1;
	flags->links_len = 1;
	flags->size_len = 1;
	flags->max_name_len = 1;
}

void		ls_read_directories(t_list **node, t_ls *flags, DIR *dirp,
			char *path)
{
	struct dirent	*name;
	char			*new_path;

	while ((name = readdir(dirp)))
	{
		new_path = join_path(path, name->d_name, flags);
		if (flags->a == 1)
			ls_lstadd_linkedlist(node, flags, new_path, 0);
		else if (*(name->d_name) != '.')
			ls_lstadd_linkedlist(node, flags, new_path, 0);
	}
	*node = ft_mergesort(*node, flags->fptr[0]);
	if (flags->r)
		*node = ft_lstget_last(*node);
	ls_print_files_del(node, flags, 0);
	if (flags->rec && *node)
	{
		ls_open_directories(flags, node, path);
		ls_lstdel(node, flags);
	}
	else
		ls_lstdel(node, flags);
}

void		ls_open_directories(t_ls *f, t_list **node, char *dir)
{
	DIR		*dirp;
	t_list	*cur;
	t_list	*new;

	if ((*node) == NULL)
		return (ls_lstdel(node, f));
	new = NULL;
	cur = *node;
	if (((t_file*)cur->content)->type == 'd' &&
		dont_open(((t_file*)cur->content)->path, dir))
	{
		f->ac > 1 || f->rec ? ft_printf("%s:\n",
		((t_file*)cur->content)->path) : 0;
		if ((dirp = opendir(((t_file*)cur->content)->path)))
		{
			ls_read_directories(&new, f, dirp, ((t_file*)cur->content)->path);
			if (closedir(dirp) == -1)
				ls_error(((t_file*)cur->content)->path);
		}
		else
			ls_error(((t_file*)cur->content)->name);
	}
	cur = f->r ? cur->prev : cur->next;
	ls_flags_init(f);
	ls_open_directories(f, &cur, cur ? ((t_file*)cur->content)->path : dir);
}
