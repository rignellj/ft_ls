/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/25 21:45:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
/*
	void		print_exists(void *n)
	{
		ft_printf("Exists: %d\n", *(int*)n);
	}
*/
/*
	void		print_flags(t_ls *flags)
	{
		ft_printf("a: %d\n", flags->a);
		ft_printf("l: %d\n", flags->l);
		ft_printf("r: %d\n", flags->r);
		ft_printf("R: %d\n", flags->rec);
		ft_printf("t: %d\n", flags->t);
	}
*/
static void	print_list(t_list *node, t_ls *flags)
{
	while (node && !((t_file*)node->content)->exist)
			node = node->next;
		if (!node)
			return ;
	while (node)
	{
		ls_print_content(node, flags);
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
	ft_putchar('\n');
}

static void	get_file_mode(int ac, char *av[])
{
	t_list			*node;
	t_file			*content;
	size_t			i;
	t_ls			flags;

	i = 1;
	node = NULL;
	content = NULL;
	ls_get_flags(&flags, ac, av, &i);
	while (ac > 1 && av[i])
	{
		// ft_printf("i: %d\n", i);
		ls_lstadd(&node, av[i++]);
	}
	if (ac == 1)
	{
		ls_lstadd(&node, ".");
	}
	print_list(node, &flags);//print_exists
//	print_flags(&flags);
}

int			main(int ac, char *av[])
{
	get_file_mode(ac, av);
	return (0);
}
