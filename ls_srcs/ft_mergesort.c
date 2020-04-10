/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:10:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/10 14:35:02 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list	*merge(t_list *node, t_list *middle)
{
	if (!node)
		return (middle);
	if (!middle)
		return (node);
	// ft_printf("%s %s\n", ((t_file*)node->content)->name, ((t_file*)middle->content)->name);
	if (ft_strcmp(((t_file*)node->content)->name, ((t_file*)middle->content)->name) < 0)
	{
		//  ft_printf("%s %s\n", ((t_file*)node->content)->name, ((t_file*)middle->content)->name);
		node->next = merge(node->next, middle);
		node->next->prev = node;
		node->prev = NULL;
		return (node);
	}
	else
	{
		middle->next = merge(node, middle->next);
		middle->next->prev = middle;
		middle->prev = NULL;
		return (middle);
	}
}

static t_list	*split_list(t_list *node)
{
	t_list	*right;
	t_list	*left;
	t_list	*middle;

	right = node;
	left = node;
	while (right->next && right->next->next)
	{
		right = right->next->next;
		left = left->next;
	}
	middle = left->next;
	left->next = NULL;
	return (middle);
}

t_list			*ft_mergesort(t_list *node)
{
	t_list	*middle;

	if (!node || !node->next)
		return (node);
	middle = split_list(node);
	node = ft_mergesort(node);
	middle = ft_mergesort(middle);
	return (merge(node, middle));
}
