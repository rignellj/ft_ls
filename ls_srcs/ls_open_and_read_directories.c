/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_open_and_read_directories.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:16:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/14 17:01:02 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	dont_open(char *str)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = ft_strrchr(str, '/');
	if (ptr1 == NULL)
		return (1);
	ptr1++;
	ptr2 = ptr1;
	ptr2++;
	if (*ptr1 == '.' && *ptr2 == '\0')
		return (0);
	else if (*ptr1 == '.' && *ptr2 == '.' && ft_strlen(ptr1) == 2)
		return (0);
	return (1);
}

static char	*join_path(char *path, char *name)
{
	char	*new_path;

	new_path = ft_joindel(ft_joindel(ft_strdup(path), ft_strdup("/")),
	ft_strdup(name));
	return (new_path);
}

static void	ls_flags_zero(t_ls *flags)
{
	flags->blocks = 0;
	flags->group_len = 0;
	flags->owner_len = 0;
	flags->links_len = 0;
	flags->size_len = 0;
}

void		ls_read_directories(t_list **node, t_ls *flags, DIR *dirp,
			char *path)
{
	struct dirent	*name;
	char			*new_path;

	while ((name = readdir(dirp)))
	{
		new_path = join_path(path, name->d_name);
		if (flags->a == 1)
			ls_lstadd_linkedlist(node, flags, new_path, 0);
		else
			*(name->d_name) != '.' ?
			ls_lstadd_linkedlist(node, flags, new_path, 0) : 0;
	}
	ft_mergesort(*node, flags->fptr[0]);
	*node = ls_find_first(*node);
	
	flags->l ? ft_printf("total %lld\n", flags->blocks) : 0;
	ls_print_files_del(node, flags, 0);
	*node = ls_find_first(*node);
	flags->rec && *node ? ls_open_directories(flags, node,
	((t_file*)(*node)->content)->path, 1) : 0;
}

void		ls_open_directories(t_ls *flags, t_list **node, char *dir, int i)
{
	DIR		*dirp;
	t_list	*current;
	t_list	*new_list;

	if ((*node) == NULL)
		return ;
	new_list = NULL;
	current = *node;
	if (dont_open(((t_file*)current->content)->path) && (dirp = opendir(((t_file*)current->content)->path)) != NULL)
	{
		i ? ft_putchar('\n') : 0;
		// i = 0;
		flags->ac > 1 || flags->rec ? ft_printf("%s:\n", ((t_file*)current->content)->path) : 0;
		ls_read_directories(&new_list, flags, dirp, ((t_file*)current->content)->path);
		if (closedir(dirp) == -1)
	 			ls_error();
	}
	current = current->next;
	ls_flags_zero(flags);
	ls_open_directories(flags, &current, dir, 1);
	// ls_lstdel(node, flags);
	// ft_print_current_node(node);
	// memdel function
}
