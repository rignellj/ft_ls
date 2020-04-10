/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_open_directories.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:16:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/10 17:41:44 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*join_path(char *path, char *name)
{
	char	*new_path;

	new_path = ft_joindel(ft_joindel(ft_strdup(path), ft_strdup("/")),
	ft_strdup(name));
	return (new_path);
}

/*
	static void	print_list(t_list *node, t_ls *flags)
	{
		// while (node && !((t_file*)node->content)->exist)
		// 		node = node->next;
		// 	if (!node)
		// 		return ;
		while (node)
		{
			ls_print_content(node, flags);
			node = node->next;
		
			// void(*fptr)(void*)
			// t_file	*current;
			// t_list	*cur;
			// cur = node;
			// current = node->content;
			// (*fptr)(node->content);
			// print("name: %s\n", );
			// print("exist: %d\n", ((t_file*)node->content)->exist);
			// print("links: %d\n", );
			// print("size: %d\n", ;
			// print("mode: %s\n", );
			// print("owner: %s\n", ;
			// print("group: %s\n", );
			// print("last modified: %s\n\n", );
		
		}
		ft_putchar('\n');
	}
*/
static void	ls_read_directories(t_list **node, t_ls *flags, DIR *dirp, char *path)
{
	struct dirent	*name;
	char			*new_path;
	// t_list			*current;

	// if ((*node) == NULL)
	// 	return ;
	while ((name = readdir(dirp)))
	{
		new_path = join_path(path, name->d_name);
		if (flags->a == 1)
			ls_lstadd_linkedlist(node, flags, new_path, 0);
		else
			*(name->d_name) != '.' ? ls_lstadd_linkedlist(node, flags, new_path, 0) : 0;
	}
	ft_mergesort(*node);
	*node = ls_find_first(*node);
	// print_current(node);
	ls_print_files_del(node, flags, 0);
	// flags->rec ? ls_open_directories(flags, &(*node), path) : 0;
	// flags->rec ? ls_get_files(flags, files, *node) : 0;
}

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

//1. iter: av lähettää avattavat dirs
//2. ls_directories lähettää 
void		ls_open_directories(t_ls *flags, t_list **node, char *dir)
{
	DIR		*dirp;
	t_list	*current;
	t_list	*new_list;

	if ((*node) == NULL)
		return ;
	new_list = NULL;
	current = *node;
	// dir != NULL ? join_path(node, dir) : 0;
	if (dont_open(((t_file*)current->content)->path) && (dirp = opendir(((t_file*)current->content)->path)) != NULL)
	{
		// ft_printf("ls_open: %s\n", ((t_file*)current->content)->path);
		ls_read_directories(&new_list, flags, dirp, ((t_file*)current->content)->path);
		if (closedir(dirp) == -1)
	 			ls_error();
	}
	current = current->next;
	ls_open_directories(flags, &current, dir);
	print_current(node);
/*
	linkedlist memdel
*/
}
