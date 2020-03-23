/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/23 17:15:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
/*
void		print_exists(void *n)
{
	ft_printf("Exists: %d\n", *(int*)n);
}
*/

void		print_list(t_list *node)
{
	int		(*print)(const char*, ...);

	print = &ft_printf;
	while (node)
	{
		((t_file*)node->content)->last_mod = ft_strtrim(((t_file*)node->content)->last_mod);
		print("%c%s %-2d%-2s %.7s %4d % s % s\n", ((t_file*)node->content)->type,
		((t_file*)node->content)->mode, ((t_file*)node->content)->links,
		((t_file*)node->content)->owner, ((t_file*)node->content)->group,
		((t_file*)node->content)->size, ((t_file*)node->content)->last_mod, ((t_file*)node->content)->name);
		node = node->next;
/*		
		void(*fptr)(void*)
		t_file	*current;
		t_list	*cur;
		cur = node;
		current = node->content;
		(*fptr)(node->content);
		print("name: %s\n", );
		print("exist: %d\n", ((t_file*)node->content)->exist);
		print("links: %d\n", );
		print("size: %d\n", ;
		print("mode: %s\n", );
		print("owner: %s\n", ;
		print("group: %s\n", );
		print("last modified: %s\n\n", );
*/		
	}
}

static void	get_file_mode(int ac, char *av[])
{
	t_list			*node;
	t_file			*content;
	int				i;
	t_ls			*flags;

	i = 1;
	node = NULL;
	content = NULL;
	ls_get_flags(flags, ac, av);
	while (ac > 1 && av[i])
	{
		ls_lstadd(&node, av[i++]);
	}
	print_list(node);//print_exists
}

int			main(int ac, char *av[])
{
	get_file_mode(ac, av);
	return (0);
}
